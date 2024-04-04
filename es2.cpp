/*
2) Scrivere un programma 
che unisce quanto presente 
nei file “file1.txt” e “file2.txt” nel file “unione.txt”
*/

#include <fstream>
#include <vector>

void fetch(std::ifstream& in, std::vector<std::string>& v,std::string& line){
    if(in.is_open()){
        while(getline(in,line))
            v.push_back(line);
    }
}

int main(){
    
    using std::string;
    string path_file1 = "file1.txt", path_file2 = "file2.txt", input_line;
    string final_path = "unione.txt";
    std::vector<string> string_buf;
    std::ifstream inFile;
    std::ofstream outFile;

    //fase fetch on file1
    inFile.open(path_file1);
    fetch(inFile,string_buf,path_file1);
    inFile.close();
    inFile.clear();

    //fase fetch on file2
    inFile.open(path_file2);
    fetch(inFile,string_buf,path_file2);
    inFile.close();
    inFile.clear();

    //fase writing on the union file
    outFile.open(final_path);
    if(outFile.is_open()){
        for(string& i:string_buf){
            outFile << i << std::endl;
        }
    }
    outFile.close();

    return 0;
}
