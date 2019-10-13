#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class LogIn{
	char sn[20];
	char section[10];
	public:
		LogIn()
		{
		strcpy(sn, "AGD");
		}
		void checkAccount (char userName[], char passWord[]){
			FILE *pFile = fopen ("accounts.txt", "r");
			while ( ! feof (pFile) )
			{
				char data[1000];
				fscanf (pFile, "%s", data);
				char *d = strtok(data,","); //SPLIT
				char uName[1000];
				strcpy (uName,d);
				d = strtok (NULL,",");
				char pWord [1000];
				strcpy (pWord,d);
				if(strcmpi(uName,userName) == 0 && strcmp(pWord,passWord) == 0){
					d = strtok(NULL,",");
					if(strcmp(d,"student") == 0){
						d = strtok(NULL,",");
						strcpy(sn,d);
						d = strtok(NULL,",");
						strcpy(section,d);
					}else{
						strcpy(sn,"admin");
					}
					break;
				}					
			}
			fclose (pFile);
		}
		
		char *getSN(){
			return sn;
		}
		
		char *getSection(){
			return section;
		}
		
};

