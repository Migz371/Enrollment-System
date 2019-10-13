#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Admin {
	
	public:
		void CreatAccount (){
			FILE *crtAccnt = fopen ("accounts.txt", "a");
			char studentNumber[100];
			cout << "Enter Student Number: ";
			cin >> studentNumber;
			cout << "Enter UserName: ";
			char uName[100];
			cin >> uName;
			cout << "Enter Password: ";
			char pWord[100];
			cin >> pWord;
			system ("CLS");
			cout << "Account Created!" << endl;
			cout << "Username: " << uName << endl;
			cout << "Password: " << pWord << endl;
			cout << "=========================================================" << endl;
			cout << "                  Student Information" << endl;
			cout << "=========================================================" << endl;
			cout << "Student Number: " << studentNumber << endl;
			char section[10];
			cout << "Enter Section to be placed: ";
			cin >> section;
			fprintf (crtAccnt, "\n%s,%s,%s,%s,%s", uName, pWord, "student", studentNumber,section);
			fclose(crtAccnt);
			
			
			char fileName[100];
			{//Student File based student number
				strcpy(fileName,studentNumber);
				strcat(fileName, ".txt");
			}
			
			FILE *pProfile = fopen (fileName, "w");
			{// Personal Profile
				char lname[30];
				cout << "Enter Last Name: ";
				cin >> lname;
				char fname[30];
				cout << "Enter First Name: ";
				cin>> fname;
				char bMonth[10];
				cout << "Enter Month of Birth: ";
				cin >> bMonth;
				int bDay;
				cout << "Enter Day of Birth: ";
				cin >> bDay;
				int bYear;
				cout << "Enter Year of Birth: ";
				cin >>bYear;
				char citizenship[30];
				cout << "Enter Citizenship: ";
				cin >> citizenship;
				int age;
				cout << "Enter Age: ";
				cin >> age;
				char gender;
				cout << "Enter Gender: ";
				cin >> gender;
				int yearLevel;
				cout << "Enter Year Level: ";
				cin >> yearLevel;
				fprintf(pProfile, "%s,%s,%s,%i,%i,%s,%i,%c,%i", lname, fname, bMonth, bDay, bYear, citizenship,age, gender, yearLevel);
				fclose(pProfile);
			}
			
		}
		
		void CreateCourse(){
			//Creation of subjects
			FILE *crtCourse = fopen ("subjects.txt", "a");
			cout << "Enter Course Code: ";
			char courseCode[30];
			cin >> courseCode;
			cout << "Enter Course Name: ";
			char courseName[20];
			cin >> courseName;
			fprintf (crtCourse, "\n%s,%s", courseCode, courseName);
			fclose(crtCourse);
			
			char fileName[100];
			char fileNamestud[100];
			{//Subject File based on Course Name
				strcpy(fileNamestud,courseName);
				strcat(fileNamestud, "students.txt");
				strcpy(fileName,courseName);
				strcat(fileName, ".txt");
			}
			FILE *pSubject = fopen (fileNamestud, "a");
			fclose(pSubject);
			pSubject = fopen (fileName, "a");
			fclose(pSubject);
			
		}
		
		void AddSchedule(){
			FILE *showcourse = fopen ("subjects.txt", "r");
				cout << "Available Courses:" << endl;
				while( ! feof (showcourse) ){
						char data[1000];
						fscanf (showcourse, "%s", data);
						char *d = strtok(data,",");
						cout << "[" << d << "] ";
						d = strtok(NULL,",");
						cout << d << endl;
		}
				cout << "Enter name of course: ";
				char fileName[20];
				cin >> fileName;	
				strcat(fileName,".txt");
			FILE *updateCourse = fopen (fileName, "a");
			{// Subject Detail
				cout << "Enter Course Section: ";
				char courseSection[20];
				cin >> courseSection;
				cout << "Enter Course Day: ";
				char courseDay[20];
				cin >> courseDay;
				cout << "Enter Course Time: ";
				char courseTime[20];
				cin >> courseTime;
				cout << "Enter Course Room: ";
				char courseRoom[20];
				cin >> courseRoom;
				fprintf(updateCourse, "\n%s,%s,%s,%s", courseSection, courseDay, courseTime, courseRoom);
				fclose(updateCourse);
				
			} 
		}

		
		
		
		void ViewSubjects(){
			
			FILE *fViewSubject = fopen ("subjects.txt", "r");
			while ( ! feof (fViewSubject)){
				char data[500];
				fscanf (fViewSubject, "%s", data);
				char *d = strtok(data,",");
				cout << "["<< d << "]" << ": ";
				d = strtok(NULL,",");
				cout << d << endl;
				if ( feof (fViewSubject)){
					break;
				}
			}
			fclose(fViewSubject);
				
			
		}
		
		void ViewEnrolled (){
			FILE *fViewSubject = fopen ("subjects.txt", "r");
			while ( ! feof (fViewSubject)){
				char data[500];
				fscanf (fViewSubject, "%s", data);
				char *d = strtok(data, ",");
				cout << "[" << d << "]" << ": ";
				d = strtok (NULL, ",");
				cout << d <<endl;
			}
			fclose (fViewSubject);
			cout << "Enter Subject Name to View: " <<endl;
			char subName[50];
			cin >> subName;
			strcat (subName, "students.txt");
			FILE *enrolled = fopen (subName, "r");
			cout << "Students Enrolled: " <<endl;
			do {
				if ( ! feof (enrolled) ){
				char data[500];
				fscanf(enrolled, "%s", data);
				char *d = strtok (data, ",");
				char sn[100];
				strcpy (sn,d);
				d = strtok (NULL, ",");
				char lName[100];
				strcpy (lName,d);
				d = strtok (NULL, ",");
				char fName[100];
				strcpy (fName,d);
				cout << sn << ' ' << lName << ", " << fName <<endl;
			} 
				
				
			}while ( ! feof  (enrolled));
			
		}

		
		void UpdateRecord(){
			cout << "Enter Student's Student Number: ";
			char studentNumber[100];
			cin >> studentNumber;
			char sn[100];
			char studnum[100];
			strcpy(sn,studentNumber);
			strcpy(studnum,studentNumber);
			strcat(sn,".txt");
				FILE *getname = fopen (sn, "r");
						char data[1000];
						fscanf (getname, "%s", data);
						char *d = strtok(data,",");
						char lname[50];
						strcpy(lname,d);
						d = strtok(NULL,",");
						char fname[50];
						strcpy(fname,d);
						fclose(getname);
						
				
				FILE *updaterec = fopen ("accounts.txt", "r");
					
					while( ! feof (updaterec) ){
						char data[1000];
						fscanf (updaterec, "%s", data);
						char *d = strtok(data,",");
						d = strtok (NULL,",");
						d = strtok (NULL,",");
						d = strtok (NULL,",");
							
							if(strcmpi(studentNumber,d) == 0){	
								fclose (updaterec);
								strcat(studentNumber, ".txt");
							FILE *updaterec = fopen (studentNumber,"w");
								cout << "===========================" << endl;
								cout << "        Update Record" << endl;
								cout << "===========================" << endl;
								cout << "Full Name: " << fname << " " << lname << endl;
								cout << "Student Number: " << studnum << endl;
								char bMonth[10];
								cout << "Enter Month of Birth: ";
								cin >> bMonth;
								int bDay;
								cout << "Enter Day of Birth: ";
								cin >> bDay;
								int bYear;
								cout << "Enter Year of Birth: ";
								cin >>bYear;
								char citizenship[30];
								cout << "Enter Citizenship: ";
								cin >> citizenship;
								int age;
								cout << "Enter Age: ";
								cin >> age;
								char gender;
								cout << "Enter Gender: ";
								cin >> gender;
								int yearLevel;
								cout << "Enter Year Level: ";
								cin >> yearLevel;
								fprintf(updaterec, "%s,%s,%s,%i,%i,%s,%i,%c,%i", lname, fname, bMonth, bDay, bYear, citizenship,age, gender, yearLevel);
								fclose(updaterec);
								break;
							}else if(feof (updaterec) ){
									cout << "Student not found! " << endl;
									cout << "Enter any key to continue ";
									string dummy;
									cin >> dummy;
								
								
					}
						
						
					} // test end
		}
	
};
