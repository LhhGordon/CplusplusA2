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
            string vitalsStr;

            getline(fileString, uid, '/');
            getline(fileString, birthdayStr, '/');
            getline(fileString, name, '/');
            getline(fileString, diagnosises, '/');
            getline(fileString, vitalsStr, '/');

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

            //patient 
            Patient* patient = new Patient(fname, lname, birthday);

            //diagnosis
            istringstream diagnosisStream(diagnosises);
            string diagnosis;
            while (getline(diagnosisStream, diagnosis, ','))
            {
                patient->addDiagnosis(diagnosis);
            }

            //vitals
            if (vitalsStr != "")
            {
                istringstream vitalsStream(vitalsStr);
                string vitals;

                while (getline(vitalsStream, vitals, ';'))
                {
                    string heartRate;
                    string oxygenSaturation;
                    string bodyTemperature;
                    string brainActivity;

                    istringstream eachVitalStream(vitals);

                    getline(eachVitalStream, heartRate, ',');
                    getline(eachVitalStream, oxygenSaturation, ',');
                    getline(eachVitalStream, bodyTemperature, ',');
                    getline(eachVitalStream, brainActivity, ',');

                    patient->addVitals(new Vitals(stoi(heartRate), stoi(oxygenSaturation), stoi(bodyTemperature), stoi(brainActivity)));
                }
            }
            patient->debugUse();
            patients.push_back(patient);
        }
    }
    return patients;
}
