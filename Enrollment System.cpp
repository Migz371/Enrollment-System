#include "MyLogIn.h" 
#include "MyAdmin.h"
#include "MyStudent.h"

int main (){
	char uName[100];
	char pWord[100];
	char studentNumber[100];
	LogIn log;
	int choice;
	
	cout << "Simple Enrollment System with Student Profile Management" <<endl;
	while (1){
		cout << "Enter Username: ";
		cin >> uName;
		cout << "Enter Password: ";
		cin >> pWord;
		log.checkAccount(uName, pWord);
		if (strcmp(log.getSN(), "AGD") == 0){
			cout << "Access Denied!!!!\n";
		}else{
			break;
		}
	}
	cout << "Access Granted!!!\n";
	if (strcmp(log.getSN(),"admin") == 0){
		system ("CLS");
		cout << "Welcome Admin!" <<endl;
		
		do{
			Admin ad;	
			cout << "\n----------------------------------------" <<endl;
			cout << "[1] Create Student Account" <<endl;
			cout << "[2] Create Course" <<endl;
			cout << "[3] Add Schedule" << endl;
			cout << "[4] View Subjects" <<endl;
			cout << "[5] View Students Enrolled on a Course" <<endl;
			cout << "[6] Update Records" <<endl;
			cout << "[7] Exit" <<endl;
			cout << "Enter choice: ";
			cin >> choice;
			system ("CLS");
			if(choice == 1){
				cout << "Create Student Account" <<endl;
				ad.CreatAccount();
				cout << "Done!" <<endl;
			} else if (choice == 2){
				cout << "Create Course" <<endl;
				ad.CreateCourse();
				cout << "Done!" <<endl;
			} else if (choice == 3){
				cout << "Add Schedule" <<endl;
				ad.AddSchedule();
				cout << "Done!" <<endl;
			}else if(choice == 4){
				cout << "View Subjects" <<endl <<endl;
				ad.ViewSubjects();
			}else if(choice == 5){
				cout << "Students Enrolled" <<endl;
				ad.ViewEnrolled();
			}else if(choice == 6){
				cout << "Update Records" <<endl;
				ad.UpdateRecord();
			}
			
		} while (choice != 7);
		
		
	

	}else{
		do{
		system ("CLS");
		cout << "Welcome Student!" <<endl;
		Student s;
		cout << "----------------------------------------" <<endl;
		cout << "[1] Student Profile" <<endl;
		cout << "[2] Add Subjects" <<endl;
		cout << "[3] View Schedule" <<endl;
		cout << "[4] Exit" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		
		if (choice == 1){
			system ("CLS");
			cout << "==============================================" << endl;
			cout << "          Welcome to Your Profile!" <<endl;
			cout << "==============================================" << endl;
			s.studentProfile(log.getSN(),log.getSection());
			string dummy;
			cout << endl << "==============================================" << endl;
			cout << endl<< "Enter any key to continue "; 
			cin >> dummy;
			
		}else if (choice == 2){
			cout << "Add Subjects" <<endl;
			s.addSubject(log.getSN(),log.getSection());
			
			
		}else if (choice == 3){
			cout <<"View Schedule" << endl;
			s.viewSchedule(log.getSN(),log.getSection());
		}	
		
	}while(choice != 4);
		
		
	
		
	}
		
		
	
		
		

	
	
	
	
	
}
