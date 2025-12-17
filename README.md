# AS_Connectivity
Analyzing Network Connectivity Using BGP Data

  Overview
This project analyzes Internet Autonomous System (AS) connectivity using real-world BGP routing table data. 
It is implemented as two C++ programs that process routing traces via standard input/output redirection to extract AS paths and compute AS-level connectivity statistics.
The final output identifies the top 10 most connected Autonomous Systems based on unique neighbor counts.


  Part I — ASPATH Extraction & Cleaning
  Program: proj1_p1.cpp

  Purpose
Parses raw BGP routing table entries and extracts a cleaned ASPATH field suitable for graph analysis.
Implementation Details
Reads each line from standard input
Splits the line using | delimiters
Extracts the 7th field (ASPATH) if present
Handles real-world BGP edge cases:
ASSET removal
Any ASSET (enclosed in []) is removed by truncating the ASPATH at the first [
Duplicate AS elimination
Consecutive duplicate AS numbers are removed while preserving order
  
Example Transformation
Input ASPATH:
1239 7911 7911 7911 30033 30033
Output ASPATH:
1239 7911 30033
  
Output
Each cleaned ASPATH is written as a single line to standard output, with AS numbers separated by spaces.
Example Usage
./proj1_p1.x < rib_data_file > cleaned_aspath.txt


  
  Part II — AS Connectivity Analysis
  Program: proj1_p2.cpp
  
  Purpose
Builds an implicit AS-level graph from cleaned ASPATHs and computes the number of unique neighbors per AS.
Implementation Details
Reads cleaned ASPATH lines from standard input
Tokenizes each line into AS numbers
  
For every adjacent AS pair:
Adds each AS as a neighbor of the other
Prevents duplicate neighbor entries
  
  Key Logic
Self-neighbors are ignored
Neighbor relationships are bidirectional
Neighbors appearing across multiple paths are only counted once
Sorting & Ranking
  
After processing all paths:
ASes are sorted by:
Descending number of neighbors
Ascending AS number (tie-breaker)
The top 10 ASes are printed (or fewer if less than 10 exist)
                             
Example Output
701: 1780

Example End-to-End Execution
./proj1_p1.x < rib_data_file > cleaned_aspath.txt
./proj1_p2.x < cleaned_aspath.txt > top10_as.txt
                        
