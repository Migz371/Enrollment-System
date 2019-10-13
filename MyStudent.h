#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string.h>
#include <stdlib.h>
using namespace std;
class Student{
	struct Profile{
		char firstName[30];
		char lastName[30];
		int age;
		char citizenship[30];
		char studnum[40]; 
		
	}p;

	public:
		void studentProfile(char studentNumber[],char section[]){
			strcpy(p.studnum,studentNumber);
			strcat(p.studnum, ".txt");
			FILE *fRecord = fopen(p.studnum,"r");
			while( ! feof (fRecord) ){
				char data[1000];
				fscanf(fRecord, "%s", data); //lastname,firstname,age,gender,address
				char *d = strtok(data,",");
				cout << "Student Number: " << studentNumber << endl;
				strcpy(p.lastName,d);
				d = strtok(NULL,",");
				cout << "Name: " << d << " " << p.lastName << endl;
				cout << "Section: " << section << endl;
				d = strtok(NULL,",");
				cout << "Date of Birth: " << d << " ";
				d = strtok(NULL,",");
				cout << d << ", ";
				d = strtok(NULL,",");
				cout << d << endl;
				d = strtok(NULL,",");
				strcpy(p.citizenship,d);
				d = strtok(NULL,",");
				cout << "Age: " << d << endl;
				cout << "Citizenship: " << p.citizenship << endl;
				d = strtok(NULL,",");
				cout << "Gender: " << d << endl;
				d = strtok(NULL,",");
				cout << "Year Level: " << d << endl; 
	}
			fclose (fRecord);
		}
		
		void addSubject(char studentNumber[], char section[]){		
			strcpy(p.studnum, studentNumber);
			strcat(p.studnum, ".txt");
			FILE *fStudent = fopen (p.studnum, "r");
			char data[1000];
			fscanf (fStudent, "%s", data);
			char *d = strtok(data, ",");
			strcpy(p.lastName, d);
			d = strtok(NULL, ",");
			strcpy (p.firstName, d);
			fclose(fStudent);
				
			
			FILE *fAddSubject = fopen ("subjects.txt", "r");
			while ( ! feof (fAddSubject)){
				char data[100];
				fscanf (fAddSubject, "%s", data);
				char *d = strtok(data,",");
				cout << "["<< d << "]" << ": ";
				d = strtok(NULL,",");
				cout << d << endl;
				if ( feof (fAddSubject)){
						break;
			 }
				
			}
			fclose (fAddSubject);
			cout << "Enter Subject Name: ";
			char subName[50];
			cin >> subName;
			char f[100];
			strcpy(f,subName);
			strcat(f,"students.txt");
			FILE *fEnrollSub = fopen(f,"r");
			fclose(fEnrollSub);
			fEnrollSub = fopen(f,"a");
			fprintf (fEnrollSub, "\n%s,%s,%s,%s", studentNumber, p.lastName, p.firstName,section);
			fclose(fEnrollSub);
			cout << "Enter any key to continue....." <<endl;
			string dummy;
			cin >> dummy;
			
			
		}
//		
		
		void viewSchedule(char studentnumber[],char section[]){
			FILE *viewSched = fopen ("subjects.txt", "r");
			while ( ! feof (viewSched)){
				char data[500];
				fscanf (viewSched, "%s", data);
				char *d = strtok(data,",");
				char coursecode[50];
				strcpy(coursecode,d);
				char subject[50];
				char subjecthold[50];
				d = strtok(NULL,",");
				strcpy(subject,d);
				strcpy(subjecthold,d);
				strcat(d,"students.txt");
			FILE *subjectexplore = fopen (d, "r");
			while (! feof (subjectexplore)){ //2nd loop
				char data[500];
				fscanf (subjectexplore, "%s", data);
				char *d = strtok(data,",");\
				char sn[50];
				strcpy(sn,d);  
					if(strcmpi(sn,studentnumber) == 0){
						strcat(subject,".txt");
				//		cout << subject << " = var subj" << endl; //clear
						FILE *subjectinfo = fopen (subject, "r"); 
						while ( ! feof (subjectinfo)){ //4th loop
							char data[500];
							fscanf (subjectinfo, "%s", data);
							char *d = strtok(data,",");
	//						cout << "4th loop  " << d << " = var d" << subject << " = var subj " << endl;
								if(strcmpi(d,section) == 0){
									d = strtok(NULL,",");
									cout << coursecode << " " << subjecthold << " " << d << " ";
									d = strtok(NULL,",");
									cout << d << " ";
									d = strtok(NULL,",");
									cout << d << endl;
									
							}
						}
					}				
		}
	}
	string dummy;
	cin >> dummy;
		}

	
};
