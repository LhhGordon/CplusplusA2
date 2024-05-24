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
            string birthday;
            string name;
            string diagnosis;
            string vital;

            getline(fileString, uid, '/');
            getline(fileString, birthday, '/');
            getline(fileString, name, '/');
            getline(fileString, diagnosis, '/');
            getline(fileString, vital, '/');

            cout << "--testing--\n";
            cout << "uid: "<< uid <<"\n";
            cout << "birthday: " << birthday << "\n";
            cout << "name: " << name << "\n";
            cout << "diagnosis: " << diagnosis << "\n";
            cout << "vital: " << vital << "\n";
            cout << "--ending--\n";
        }

        

        

      

    }

    return patients;
}
