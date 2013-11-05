/*
	A simple html webpage generator.

	Created by Elijah Wilson. 2013.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

//Declare functions
void makeHtml4(ofstream& outFile);						//Creates html4 doctype
void makeHtml5(ofstream& outFile);						//Creates html5 doctype
void printVersion(ofstream& outFile);					//Prints date & time when file is created
void getTitle(string& title);							//Gets what the user wants the title to be
void printHead(ofstream& outFile, string title);		//Prints the head portion of the page
void printBody(ofstream& outFile, string title);		//Prints the rest of the webpage
void outputHeader();									//Outputs header to the screen

int main()
{
	string fileName, title;
	char markup;

	outputHeader();

	cout << "Please enter the desired file name (without '.html'): ";
	cin >> fileName;

	fileName.append(".html");	//Adds html file extension

	ofstream outFile;
	outFile.open(fileName.c_str(), ios::out | ios::app);

	//Incase the output file failed to be opened
	if(outFile.fail())
	{
		cout << "outFile failed" << endl;
	}

	cout << endl;
	cout << "Your file is named: " << fileName << endl;

	cout << endl;
	cout << "Would you like html 4 or 5 markup? (4 or 5; 'q' to quit): ";
	cin >> markup;

	switch(markup)
	{
		case '4' :
			makeHtml4(outFile);
			cout << "Html4 created" << endl;
		break;
		case '5' :
			makeHtml5(outFile);
			cout << "Html5 created" << endl;
		break;
		case 'q' :
			cout << "Quitting...." << endl << endl;
			cout << "*< exited successfully >*" << endl;
			return 1;
		break;
		default :
		break;
	}

	while(!((markup == '4') || (markup == '5') || (markup == 'q')))
	{
		cout << "That is an invalid input. Input 4 or 5 ('q' to stop): ";
		cin >> markup;

		switch(markup)
		{
			case '4' :
				makeHtml4(outFile);
				cout << "Html4 created" << endl;
			break;
			case '5' :
				makeHtml5(outFile);
				cout << "Html5 created" << endl;
			break;
			case 'q' :
				cout << "Quitting...." << endl << endl;
				cout << "*< exited successfully >*" << endl;
				return 1;
			break;
			default :
			break;
		}
	}

	printVersion(outFile);
	getTitle(title);
	printHead(outFile, title);
	printBody(outFile, title);

	outFile.close();

	cout << endl;
	cout << "*< done >*" << endl;

	return 0;
}

void makeHtml4(ofstream& outFile)
{
	outFile << "<!DOCTYPE HTML>" << endl;
}
void makeHtml5(ofstream& outFile)
{
	outFile << "<!DOCTYPE html>" << endl;
}
void printVersion(ofstream& outFile)
{
	outFile << "<!--" << endl
			<< "\tThis webpage was generated using the htmlMaker program created by" << endl
			<< "\tElijah Wilson. On ";

	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    outFile << (now->tm_year + 1900) << '-' 
         	<< (now->tm_mon + 1) << '-'
         	<<  now->tm_mday;

    outFile << "." << endl;
    outFile << "-->" << endl;
}
void getTitle(string& title)
{
	cout << endl;
	cout << "What would you like the title of your webpage to be? ";

	cin.ignore(256, '\n');
	getline(cin, title);

	cout << "OK!" << endl;
}
void printHead(ofstream& outFile, string title)
{
	cout << endl;
	cout << "Generating head...." << endl;
	outFile << "<html>" << endl;
	outFile << "<head>" << endl;
	outFile << "\t<title>" << title << "</title>" << endl;
	outFile << "</head>" << endl;
}
void printBody(ofstream& outFile, string title)
{
	cout << "Generating body...." << endl;

	outFile << "<body>" << endl;
	outFile << "\t<!-- Main body goes here -->" << endl;
	outFile << "\t<h1>" << title << "</h1>" << endl;
	outFile << "\t<p> Welcome to my webpage!<p>" << endl;
	outFile << "</body>" << endl;
	outFile << "</html>" << endl;
}
void outputHeader()
{
	cout << "Welcome to the htmlMaker created by Elijah Wilson! (v0.0.1)" << endl;
	cout << "Let's get started..." << endl;
	cout << "Initializing program..." << endl << endl;
}