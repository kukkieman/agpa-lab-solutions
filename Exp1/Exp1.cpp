#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;

int main(){
    ifstream dfile;
    string word, fword;
    char s;
    int userpoint=0, turn=0;
    dfile.open("checker-dict.txt");
    while(1){
      cout<<"INPUT WORD: ";
    	cin>>word;
    	int prevpoint=userpoint;
    	while(dfile >> fword){
    		if(turn==0){
    			turn++;
    			if(word==fword){
    				userpoint++;
    				s=word[word.length()-1];
            fword=" ";
    				//remove(fword);
    				break;
				  }
			}
			if(word==fword && word[0]==s){
    			userpoint++;
    			s=word[word.length()-1];
          fword=" ";
    			//remove(fword);
    			break;
			}
		}
		if(userpoint==prevpoint){
			cout<<"INVALID WORD. GAME OVER.";
			cout<<"\nPLAYER POINTS: "<<userpoint<<endl;
			exit(0);
		}
		dfile.seekg(0);
		while(dfile >> fword){
			if(fword[0]==s){
				cout<<"COMPUTER'S WORD: "<<fword<<endl;
				s=fword[fword.length()-1];
        fword=" ";
				//remove(fword);
				break;
			}
		}
	}
}
