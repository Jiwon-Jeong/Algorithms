#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    
    // step1
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower); 
    
    // step2
    auto filter2 = [](char c){
        return !(c == '-' || c == '_' || c == '.' ||
            (c >= 'a' && c<='z') || (c>='0' && c<='9'));
    };
    new_id.erase(remove_if(new_id.begin(), new_id.end(), filter2), new_id.end());
    
    // step3
    for(int i = 1; i < new_id.length(); ){
        if (new_id[i] == '.' && new_id[i - 1] == '.'){
            new_id.erase(new_id.begin() + i);
            continue;
        }
        else ++i;
    }
    
    //step4
    if (new_id.length()){
        if (new_id[0] == '.')
            new_id.erase(new_id.begin());
        if (new_id[new_id.length() - 1] == '.')
            new_id.erase(new_id.end()-1);   
    }
    
    // step5
    if(!new_id.length())  
        new_id = "a";
    
    // step6
    if (new_id.length() > 15){
        new_id.erase(15, new_id.length() - 15);
        if (new_id[new_id.length() - 1] == '.')
            new_id.erase(new_id.end() - 1);
    }
    
    // step 7
    if (new_id.length() <= 2){
        auto c = new_id.back();
        while (new_id.length() < 3)
            new_id += c;
    }
    
    return new_id;
}
