#include <iostream>
#include"tinyxml2.h"
#include <vector>

using namespace std;
using namespace tinyxml2;

typedef float  float32_t;
typedef double float64_t;


// /**
// *  The direction when the aircraft changes its heading to adapt to the heading at the waypoint.
// */
// typedef enum  DJIWaypointV2TurnMode:uint8_t {

//   /**
//    *  The aircraft's heading rotates clockwise.
//    */
//     DJIWaypointV2TurnModeClockwise,

//   /**
//    *  The aircraft's heading rotates counterclockwise.
//    */
//     DJIWaypointV2TurnModeCounterClockwise,

//   /**
//    *  Changes the heading of the aircraft by rotating the aircraft anti-clockwise.
//    */
//     DJIWaypointV2TurnModeUnknown = 0xFF,
// }DJIWaypointV2TurnMode;

// /**
// *  Waypoint flight path mode.
// */
// typedef enum  DJIWaypointV2FlightPathMode:uint8_t {

//   /**
//    *  In the mission, the aircraft will go to the waypoint along a curve and fly past the waypoint.
//    */
//     DJIWaypointV2FlightPathModeGoToPointAlongACurve,

//   /**
//    *  In the mission, the aircraft will go to the waypoint along a curve and stop at the waypoint.
//    */
//     DJIWaypointV2FlightPathModeGoToPointAlongACurveAndStop,

//   /**
//    *  In the mission, the aircraft will go to the waypoint along a straight line and stop at the waypoint.
//    */
//     DJIWaypointV2FlightPathModeGoToPointInAStraightLineAndStop,

//   /**
//    *  In the mission, the aircraft will fly from the previous waypoint to the next waypoint along a smooth curve without stopping at this waypoint.
//    *  the next in a curved motion,  adhering to the ``DJIWaypointV2_dampingDistance``, which is
//    *  set in ``DJIWaypointV2``.
//    */
//     DJIWaypointV2FlightPathModeCoordinateTurn,

//   /**
//    *  In the mission, the aircraft will go to the first waypoint along a straight line.
//    *  This is only valid for the first waypoint.
//    */
//     DJIWaypointV2FlightPathModeGoToFirstPointAlongAStraightLine,

//   /**
//    *  Straight exit the Last waypoint, Only valid for last waypoint.
//    */
//     DJIWaypointV2FlightPathModeStraightOut,

//   /**
//    *  Unknown
//    */
//     DJIWaypointV2FlightPathModeUnknown = 0xFF,
// }DJIWaypointV2FlightPathMode;
// typedef struct WaypointV2Config
//   {
//     /*! 0: set local waypoint's cruise speed,
//      *  1: unset local waypoint's cruise speed*/
//     uint16_t  useLocalCruiseVel:1;

//     /*! 0: set local waypoint's max speed,
//      *  1: unset local waypoint's max speed*/
//     uint16_t  useLocalMaxVel:1;

//     uint16_t  reserved :14;

//   }WaypointV2Config;


// typedef struct RelativePosition{
//   float32_t positionX; /*! X distance to reference point, North is positive*/
//   float32_t positionY; /*! Y distance to reference point, East is positive*/
//   float32_t positionZ; /*! Z distance to reference point, UP is positive*/
// } RelativePosition;

// /**
// *  Represents current aircraft's heading mode on current waypoint.
// */
// typedef enum  DJIWaypointV2HeadingMode:uint8_t {

//   /**
//    *  Aircraft's heading will always be in the direction of flight.
//    */
//     DJIWaypointV2HeadingModeAuto,

//   /**
//    * Aircraft's heading will be set to the heading when reaching the first waypoint.
//    * Before reaching the first waypoint, the aircraft's heading can be controlled by
//    * the remote controller. When the aircraft reaches the first waypoint, its
//    * heading will be fixed.
//    */
//     DJIWaypointV2HeadingFixed,

//   /**
//    *  The aircraft's heading in the mission can be controlled by the remote controller.
//    */
//     DJIWaypointV2HeadingManual,

//   /**
//    * In the mission, the aircraft's heading will change dynamically and adapt to the heading set at the next waypoint.
//    * See ``DJIWaypointV2_heading`` to preset the heading.
//    */
//     DJIWaypointV2HeadingWaypointCustom,

//   /**
//    *  Aircraft's heading will always toward point of interest.
//    *  using ``DJIWaypointV2_pointOfInterest`` setting point of interest coordiate and ``DJIWaypointV2_pointOfInterestAltitude``
//    *  setting point of interset altitute.
//    */
//     DJIWaypointV2HeadingTowardPointOfInterest,

//   /**
//    *  The aircraft's heading rotate simultaneously with its gimbal's yaw.
//    */
//     DJIWaypointV2HeadingGimbalYawFollow,

//   /**
//    *  Unknown.
//    */
//     DJIWaypointV2HeadingUnknown = 0xFF,
// }DJIWaypointV2HeadingMode;

// struct Waypoint{

// 	float64_t longitude;//经度
//   float64_t latitude;//纬度
//   float32_t relativeHeight;//相对起飞点高度

// 	DJIWaypointV2FlightPathMode   waypointType;
// 	DJIWaypointV2HeadingMode      headingMode;
// 	WaypointV2Config config;
// 	uint16_t dampingDistance;
// 	float32_t heading;
// 	DJIWaypointV2TurnMode turnMode;
// 	RelativePosition pointOfInterest;
// 	float32_t maxFlightSpeed;
// 	float32_t autoFlightSpeed;
// };
// /**
// *  Actions will be taken when the waypoint mission is finished.
// */
// enum DJIWaypointV2MissionFinishedAction:uint8_t {

//   /**
//    *  No further action will be taken.
//    *  The aircraft can be controlled by the remote controller.
//    */
//     DJIWaypointV2MissionFinishedNoAction,

//   /**
//    *  Goes home when the mission is finished. The aircraft will
//    *  land directly if it is within 20 meters away from the home point.
//    */
//     DJIWaypointV2MissionFinishedGoHome,

//   /**
//    *  The aircraft will land automatically at the last waypoint.
//    */
//     DJIWaypointV2MissionFinishedAutoLanding,

//   /**
//    *  The aircraft will go back to the first waypoint and hover.
//    */
//     DJIWaypointV2MissionFinishedGoToFirstWaypoint,

//   /**
//    *  When the aircraft reaches its final waypoint, it will hover without ending the
//    *  mission. The joystick  can still be used to pull the aircraft back along its
//    *  previous waypoints. The only way this mission  can end is if stopMission is
//    *  called.
//    */
//     DJIWaypointV2MissionFinishedContinueUntilStop
// };
// /**
// *  Possible flight mode to executes the mission.
// */
// enum  DJIWaypointV2MissionGotoFirstWaypointMode:uint8_t {

//   /**
//    *  Go to the waypoint safely. The aircraft will rise to the same altitude of the
//    *  waypoint if the current  altitude is lower then the waypoint altitude. It then
//    *  goes to the waypoint coordinate from the current  altitude, and proceeds to the
//    *  altitude of the waypoint.
//    */
//     DJIWaypointV2MissionGotoFirstWaypointModeSafely,

//   /**
//    *  Go to the waypoint from the current aircraft point to the waypoint directly.
//    */
//     DJIWaypointV2MissionGotoFirstWaypointModePointToPoint,
// };


// typedef struct WayPointV2InitSettings{

//   uint32_t missionID;//任务ID区分不同任务

//   uint16_t missTotalLen;//任务点长度最多65535个

//   uint8_t repeatTimes;//任务执行重复次数0代表执行一次1代表两次

//   DJIWaypointV2MissionFinishedAction finishedAction;//航点任务完成后的动作

//   float32_t maxFlightSpeed;//最大速度速度在2-15如果为负数倒着开到上个航点

//   float32_t autoFlightSpeed;//自动速度，当自动速度大于0时实际速度=操纵杆速度+自动速度，小于0时在第一个航点飞机将不会飞，直到遥控器加上速度来，范围-15-+15

  
//   uint8_t exitMissionOnRCSignalLost;//决定飞机与遥控锻炼时是否停止任务，默认NO

//   DJIWaypointV2MissionGotoFirstWaypointMode gotoFirstWaypointMode;//定义从当前点飞到第一个点的模式

//   std::vector<Waypoint> mission;

// }WayPointV2InitSettings;

struct waypoint{
  int16_t name;
  bool useWaylineAltitude;
  int heading;
  char turnMode;
  float32_t gimbalPitch;
  bool useWaylineSpeed;
  float32_t speed;
  bool useWaylineHeadingMode;
  bool useWaylinePointType;
  char pointType;
  char headingMode;
  float32_t cornerRadius;
  char relativeToGround;
  float64_t longitude;      //经度
  float64_t latitude;       //纬度
  float32_t relativeHeight; //相对起飞点高度
};


struct waypointline{
  float32_t autoFlightSpeed;
  char droneType;
  char cameraIndex;
  char cameraName;
  char cameraType;
  char payloadCameraType;
  bool useAbsolute;
  bool hasTakeoffHeight;
  float32_t takeoffHeight;

};
std::vector<waypoint> mission;

void GetEleValue(XMLElement * element)
{
	for (XMLElement* currentele = element->FirstChildElement(); currentele; currentele = currentele->NextSiblingElement())
	{
	    XMLElement* tmpele = currentele;
	    if (currentele->GetText() != NULL)
                cout << currentele->Name() << ":" << currentele->GetText() << endl;	
	    if (!tmpele->NoChildren())
		GetEleValue(tmpele);
	}
};
void deCodeKml()
{
	//声明
	tinyxml2::XMLDocument xml;

	//------------
	//导入kml
	//------------
	if (xml.LoadFile("test3.kml") != XML_SUCCESS){
		return;
	}
	//------------
	//找到导入根节点
	//------------
	tinyxml2::XMLElement* rootNode = xml.RootElement();
	if (rootNode == NULL) {
		return;
	}

	
/*document的属性*/
	tinyxml2::XMLElement* root_1_Document = rootNode->FirstChildElement("Document");
  const XMLAttribute *DocumentAttribute = root_1_Document->FirstAttribute();
  cout<<DocumentAttribute->Value()<< endl;
  
/*document的名字内容*/
	tinyxml2::XMLElement* root_2_name = root_1_Document->FirstChildElement("name");
  cout<< root_2_name->GetText()<<endl;
/*document的open内容*/
	tinyxml2::XMLElement* root_2_open = root_1_Document->FirstChildElement("open");
  cout<< root_2_open->GetText()<<endl;
/*扩展数据的属性、任务类型、任务状态类型*/
	tinyxml2::XMLElement* root_2_ExtendedData = root_1_Document->FirstChildElement("ExtendedData");
  const XMLAttribute *ExtendedDataAttribute =root_2_ExtendedData->FirstAttribute();
  cout<<ExtendedDataAttribute->Value()<< endl;
  tinyxml2::XMLElement* root_2_1_mis_type=root_2_ExtendedData->FirstChildElement("mis:type");
  cout<< root_2_1_mis_type->GetText()<<endl;
  tinyxml2::XMLElement* root_2_2_mis_stationType=root_2_ExtendedData->FirstChildElement("mis:stationType");
  cout<< root_2_2_mis_stationType->GetText()<<endl;

/*航线的一些风格属性（没什么用）*/
	tinyxml2::XMLElement* root_2_Style_waylineGreenPoly = root_1_Document->FirstChildElement("Style");
  const XMLAttribute *Style_waylineGreenPoly_Attribute = root_2_Style_waylineGreenPoly->FirstAttribute();
  cout<<Style_waylineGreenPoly_Attribute->Value()<< endl;

	tinyxml2::XMLElement* root_2_Style_waypointStyle = root_1_Document->LastChildElement("Style");
  const XMLAttribute *Style_waypointStyle_Attribute = root_2_Style_waypointStyle->FirstAttribute();
  cout<<Style_waypointStyle_Attribute->Value()<< endl;
  /*航点*/
	tinyxml2::XMLElement* root_2_Folder = root_1_Document->FirstChildElement("Folder");
	tinyxml2::XMLElement* root_3_name = root_2_Folder->FirstChildElement("name");//名称
  cout<<root_3_name->GetText()<< endl;
	tinyxml2::XMLElement* root_3_description = root_2_Folder->FirstChildElement("description");//描述
	cout<<root_3_description->GetText()<< endl;
  //tinyxml2::XMLElement* root_3 = root_2_Folder->FirstChildElement("Placemark");
  /*进入连续的Placemark*/
  for(tinyxml2::XMLElement* root_3 = root_2_Folder->FirstChildElement("Placemark");;root_3= root_3->NextSiblingElement()){
    
      tinyxml2::XMLElement* name = root_3->FirstChildElement("name");
      cout<<name->GetText()<< endl;
      tinyxml2::XMLElement* visibility = root_3->FirstChildElement("visibility");
      cout<<visibility->GetText()<< endl;
      tinyxml2::XMLElement* description = root_3->FirstChildElement("description");
      cout<<description->GetText()<< endl;
      tinyxml2::XMLElement* styleUrl = root_3->FirstChildElement("styleUrl");
      cout<<styleUrl->GetText()<< endl;

      tinyxml2::XMLElement* ExtendedData = root_3->FirstChildElement("ExtendedData");
      tinyxml2::XMLElement* actions = ExtendedData->FirstChildElement("mis:actions");
      GetEleValue(ExtendedData);//将ExtendedData全部输出

      tinyxml2::XMLElement* Point = root_3->FirstChildElement("Point");
      tinyxml2::XMLElement* altitudeMode =Point->FirstChildElement("altitudeMode");
      cout<<altitudeMode->GetText()<< endl;
      tinyxml2::XMLElement* coordinates = Point->FirstChildElement("coordinates");
      cout<<coordinates->GetText()<< endl; 

  }
  tinyxml2::XMLElement* Placemark = root_1_Document->FirstChildElement("Placemark");
  



	//------------
	//读取第一层子节点信息并打印在控制台上
	//------------
	// tinyxml2::XMLElement* root_1_NodeComputerMonitor = rootNode->FirstChildElement("Document");
	// std::string text_root_1_NodeComputerMonitor = root_1_NodeComputerMonitor->GetText();
	// cout << "text_root_1_NodeComputerMonitor = " << text_root_1_NodeComputerMonitor.c_str()<<endl;

	//------------
	//读取第二层子节点信息并打印在控制台上
	//------------
	//第一层
	// tinyxml2::XMLElement* root_0_NodeKeyboard = rootNode->FirstChildElement("Document");
	// //第二层
	// tinyxml2::XMLElement* root_1_1_NodeKeyboard = root_0_NodeKeyboard->FirstChildElement("name");
	// tinyxml2::XMLElement* root_1_2_NodeKeyboard = root_0_NodeKeyboard->FirstChildElement("open");
	// tinyxml2::XMLElement* root_1_3_NodeKeyboard = root_0_NodeKeyboard->FirstChildElement("ExtendedData");
	// tinyxml2::XMLElement* root_1_4_NodeKeyboard = root_0_NodeKeyboard->FirstChildElement("Style");
	// tinyxml2::XMLElement* root_1_5_NodeKeyboard = root_0_NodeKeyboard->FirstChildElement("Style");
	// tinyxml2::XMLElement* root_1_6_NodeKeyboard = root_0_NodeKeyboard->FirstChildElement("Folder");
	// tinyxml2::XMLElement* root_1_7_NodeKeyboard = root_0_NodeKeyboard->FirstChildElement("Placemark");


    // tinyxml2::XMLElement* root_1_NodeKeyboard = root_0_NodeKeyboard->FirstChildElement("Placemark");
	// tinyxml2::XMLElement* root_2_NodeKeyboard = root_1_NodeKeyboard->FirstChildElement("LineString");
    // tinyxml2::XMLElement* root_3_NodeKeyboardAttribute = root_2_NodeKeyboard->FirstChildElement("coordinates");
	// std::string text_root_3_NodeKeyboardAttribute = root_3_NodeKeyboardAttribute->GetText();
	// cout << "text_root_3_NodeKeyboardAttribute = " << text_root_3_NodeKeyboardAttribute.c_str() << endl;
}
int main()
{


	cout << "-----------------------begin read Kml------------------------" << endl;
	deCodeKml();
	cout << "-----------------------finished read Kml---------------------" << endl;
    return 0;
}