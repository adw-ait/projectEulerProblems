#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue> 
#include <string>
using namespace std;

int main() {
  
  ifstream namesFile;
  namesFile.open("p022_names.txt");
  
  
  string fileIn;
  namesFile >> fileIn;
  
  
  fileIn.erase(remove(fileIn.begin(), fileIn.end(), '\"'), fileIn.end());

  
  
  size_t pos = 0;
  priority_queue <string, vector<string>, greater<string>> queue;
  while ((pos = fileIn.find(",")) != string::npos) {
    queue.push(fileIn.substr(0, pos));
    fileIn.erase(0, pos + 1);
  }
  queue.push(fileIn);

  
  int count = 1;
  int sum = 0;
  while(!queue.empty()){
    string temp = queue.top();
    
    
    int itemSum = 0;
    int length = temp.length();
    for (int x = 0; x < length; x++){
      itemSum = itemSum + temp[x] - 64;
    }

    sum = sum + (itemSum * count);
    count = count + 1;

    queue.pop();
  }

  cout<<sum<<endl;
}