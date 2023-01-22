#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{

string fname="test.csv";

vector<vector<string>> zawodnicy;
vector<string> row;
string line, word;

fstream file (fname, ios::in);
if(file.is_open())
{
while(getline(file, line))
{
row.clear();

stringstream str(line);

while(getline(str, word, ','))
row.push_back(word);
zawodnicy.push_back(row);
}
}
else
cout<<"Could not open the file\n";

for(int i=0;i<zawodnicy.size();i++)
{
for(int j=0;j<zawodnicy[i].size();j++)
{
cout<<zawodnicy[i][j]<<" ";
}
cout<<"\n";
}

return 0;
}
