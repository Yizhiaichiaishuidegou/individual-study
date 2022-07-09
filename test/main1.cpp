#include <iostream>
#include"tinyxml2.h"
#include <vector>

using namespace std;
using namespace tinyxml2;

void GetEleValue(XMLElement * element, std::vector<string> &waypoint)
{
	for (XMLElement* currentele = element->FirstChildElement(); currentele; currentele = currentele->NextSiblingElement())
	{
	    XMLElement* tmpele = currentele;
	    if (currentele->GetText() != NULL){

            waypoint.push_back(currentele->GetText());
            //cout<<waypoint[0]<<endl;
            //cout << currentele->Name() << ":" << currentele->GetText() << endl;
        }	
	    if (!tmpele->NoChildren()){
		    GetEleValue(tmpele,waypoint);
        }
	}
};

void deCodeKml(){
    tinyxml2::XMLDocument xml;
    if (xml.LoadFile("test3.kml") != XML_SUCCESS){
		return;
	}
    tinyxml2::XMLElement* rootNode = xml.RootElement();
	if (rootNode == NULL) {
		return;
	}
    
    std::vector<std::vector<string>> line;
    
    tinyxml2::XMLElement* root_1_Document = rootNode->FirstChildElement("Document");
    tinyxml2::XMLElement* root_2_Folder = root_1_Document->FirstChildElement("Folder");
    for(tinyxml2::XMLElement* root_3 = root_2_Folder->FirstChildElement("Placemark");root_3!=NULL;root_3= root_3->NextSiblingElement()){
        // tinyxml2::XMLElement* ExtendedData = root_3->FirstChildElement("ExtendedData");
        // tinyxml2::XMLElement* actions = ExtendedData->FirstChildElement("mis:actions");
        std::vector<string> point;
        GetEleValue(root_3,point );
        //cout<<point[0]<<endl;
        line.push_back(point);
        
    }
    //  cout<<line.size()<<endl;
    //  cout<<line[0].size()<<endl;
    //  cout<<line[3][0]<<endl;
    // for(vector<std::vector<string>>::iterator it = line.begin();it != line.end();++it){
    //     cout<<*it<<endl;
    // }
    for(int i=0;i<line.size();++i){
        for (int j=0;j<line[0].size();++j){
             cout<<line[i][j]<<endl;   
        }
        
    }

}
int main()
{


	cout << "-----------------------begin read Kml------------------------" << endl;
	deCodeKml();
	cout << "-----------------------finished read Kml---------------------" << endl;
    return 0;
}