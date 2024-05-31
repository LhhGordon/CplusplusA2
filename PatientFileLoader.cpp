#include "PatientFileLoader.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Patient.h"
#include "Vitals.h"

using namespace std;

PatientFileLoader::PatientFileLoader(const std::string& file) :
    _file(file)
{
}

std::vector<Patient*> PatientFileLoader::loadPatientFile()
{
    std::vector<Patient*> patients;

    std::ifstream inFile(_file);
    if (inFile.is_open()) {
        // TODO: load your file here
        string line;
        istringstream fileString;

        while (getline(inFile, line))
        {
            istringstream fileString(line);

            string uid;
            string birthdayStr;
            string name;
            string diagnosises;
            string vitals;

            getline(fileString, uid, '/');
            getline(fileString, birthdayStr, '/');
            getline(fileString, name, '/');
            getline(fileString, diagnosises, '/');
            getline(fileString, vitals, '/');

            //cout << "--testing--\n";
            //cout << "uid: "<< uid <<"\n";
            //cout << "birthday: " << birthday << "\n";
            //cout << "name: " << name << "\n";
            //cout << "diagnosis: " << diagnosis << "\n";
            //cout << "vital: " << vital << "\n";
            //cout << "--ending--\n";

            //Date 
            tm birthday = {};
            istringstream dobStream(birthdayStr);
            dobStream >> get_time(&birthday, "%d-%m-%Y");

            //Name 
            string fname;
            string lname;
            istringstream nameStream(name);
            getline(nameStream, lname, ',');
            getline(nameStream, fname, ',');

            

            //diagnosis
            istringstream diagnosisStream(diagnosises);
            string diagnosis;
            while (getline(diagnosisStream, diagnosis, ','))
            {
                
            }

            //vitals
            if (vitals != "")
            {
                istringstream vitalsStream(vitals);
                
            }






        }

        

        

      

    }

    return patients;
}
