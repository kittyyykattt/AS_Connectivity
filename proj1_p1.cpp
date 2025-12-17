#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string line;

    while(getline(cin, line)){
        vector<string> fields;
        string field;
        stringstream s(line);

        while(getline(s, field, '|')){
            fields.push_back(field);
        }

        if(fields.size() > 6){
            string aspath = fields[6];

            size_t pos = aspath.find('[');
            if(pos != string::npos){
                aspath.erase(pos);
            }

            stringstream ts(aspath);
            vector<string> clean;
            string token;

            while(ts >> token){
                if(clean.empty() || clean.back() != token)
		{
                    clean.push_back(token);
                }
            			}

            for(size_t i = 0; i < clean.size(); i++){
                if (i > 0){ 
			cout << " ";
		}

                cout << clean[i];
            }

            cout << "\n";
        }
	else{
            cout << "\n";
        }
   }

    return 0;
}

