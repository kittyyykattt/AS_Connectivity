#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int findNum(vector<string> &numList, string id);

bool hasNeighbor(vector<string> &neighbors, string n);

	
int main()
{
    string line;

    vector<string> numList;
    vector<vector<string>> neighborsList;

    while(getline(cin, line)){
        if(line == "")
		continue;

        stringstream ss(line);
        
	vector<string> path;
        
	string num;
        
	while(ss >> num){
            path.push_back(num);
        }

        for(int i = 1; i < path.size(); i++){
            string a = path[i - 1];
            string b = path[i];
            if(a == b)
		    continue;

            int id = findNum(numList, a);
            
	    if(id == -1){
                numList.push_back(a);
                neighborsList.push_back(vector<string>());
                id = numList.size() - 1;
            }

            if(!hasNeighbor(neighborsList[id], b)){
                neighborsList[id].push_back(b);
            }

            int id2 = findNum(numList, b);

            if(id2 == -1){
                numList.push_back(b);
                neighborsList.push_back(vector<string>());
                id2 = numList.size() - 1;
            }

            if(!hasNeighbor(neighborsList[id2], a)){
                neighborsList[id2].push_back(a);
            }
        }


    }

    for(int i = 0; i < numList.size(); i++){
        for(int j = i + 1; j < numList.size(); j++){
            int degI = neighborsList[i].size();
            int degJ = neighborsList[j].size();
	    
	    int idI = atoi(numList[i].c_str());
	    int idJ = atoi(numList[j].c_str());

            if(degJ > degI || (degJ == degI && idJ < idI)) {
                swap(numList[i], numList[j]);
                swap(neighborsList[i], neighborsList[j]);
            }
        }

    }

    int n = numList.size();

    if(n > 10){
	    n = 10;
    }

    for(int i = 0; i < n; i++){
        cout << numList[i] << ": " << neighborsList[i].size() << "\n";
    }
return 0;
}

int findNum(vector<string> &numList, string id){
    for(int i = 0; i < numList.size(); i++){
        if(numList[i] == id)
                return i;
    }
    return -1;
}

bool hasNeighbor(vector<string> &neighbors, string n){
    for(int i = 0; i < neighbors.size(); i++){
        if(neighbors[i] == n)
                return true;
    }
    return false;
}


