/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 21.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HCALIBDATA
#define HCPP_HCALIBDATA

namespace HalconCpp
{

// Represents an instance of a camera calibration model.
class LIntExport HCalibData : public HHandle
{

public:

  // Create an uninitialized instance
  HCalibData():HHandle() {}

  // Copy constructor
  HCalibData(const HCalibData& source) : HHandle(source) {}

  // Copy constructor
  HCalibData(const HHandle& handle);

  // Create HCalibData from handle, taking ownership
  explicit HCalibData(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('calib_data')!
  virtual void AssertType(Hphandle handle) const;

public:

  // Deep copy of all data represented by this object instance
  HCalibData Clone() const;



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // read_calib_data: Restore a calibration data model from a file.
  explicit HCalibData(const HString& FileName);

  // read_calib_data: Restore a calibration data model from a file.
  explicit HCalibData(const char* FileName);

#ifdef _WIN32
  // read_calib_data: Restore a calibration data model from a file.
  explicit HCalibData(const wchar_t* FileName);
#endif

  // create_calib_data: Create a HALCON calibration data model.
  explicit HCalibData(const HString& CalibSetup, Hlong NumCameras, Hlong NumCalibObjects);

  // create_calib_data: Create a HALCON calibration data model.
  explicit HCalibData(const char* CalibSetup, Hlong NumCameras, Hlong NumCalibObjects);

#ifdef _WIN32
  // create_calib_data: Create a HALCON calibration data model.
  explicit HCalibData(const wchar_t* CalibSetup, Hlong NumCameras, Hlong NumCalibObjects);
#endif




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Free the memory of a calibration data model.
  void ClearCalibData() const;

  // Deserialize a serialized calibration data model.
  void DeserializeCalibData(const HSerializedItem& SerializedItemHandle);

  // Serialize a calibration data model.
  HSerializedItem SerializeCalibData() const;

  // Restore a calibration data model from a file.
  void ReadCalibData(const HString& FileName);

  // Restore a calibration data model from a file.
  void ReadCalibData(const char* FileName);

#ifdef _WIN32
  // Restore a calibration data model from a file.
  void ReadCalibData(const wchar_t* FileName);
#endif

  // Store a calibration data model into a file.
  void WriteCalibData(const HString& FileName) const;

  // Store a calibration data model into a file.
  void WriteCalibData(const char* FileName) const;

#ifdef _WIN32
  // Store a calibration data model into a file.
  void WriteCalibData(const wchar_t* FileName) const;
#endif

  // Perform a hand-eye calibration.
  HTuple CalibrateHandEye() const;

  // Determine all camera parameters by a simultaneous minimization process.
  double CalibrateCameras() const;

  // Remove a data set from a calibration data model.
  void RemoveCalibData(const HString& ItemType, const HTuple& ItemIdx) const;

  // Remove a data set from a calibration data model.
  void RemoveCalibData(const HString& ItemType, Hlong ItemIdx) const;

  // Remove a data set from a calibration data model.
  void RemoveCalibData(const char* ItemType, Hlong ItemIdx) const;

#ifdef _WIN32
  // Remove a data set from a calibration data model.
  void RemoveCalibData(const wchar_t* ItemType, Hlong ItemIdx) const;
#endif

  // Set data in a calibration data model.
  void SetCalibData(const HString& ItemType, const HTuple& ItemIdx, const HString& DataName, const HTuple& DataValue) const;

  // Set data in a calibration data model.
  void SetCalibData(const HString& ItemType, Hlong ItemIdx, const HString& DataName, const HString& DataValue) const;

  // Set data in a calibration data model.
  void SetCalibData(const char* ItemType, Hlong ItemIdx, const char* DataName, const char* DataValue) const;

#ifdef _WIN32
  // Set data in a calibration data model.
  void SetCalibData(const wchar_t* ItemType, Hlong ItemIdx, const wchar_t* DataName, const wchar_t* DataValue) const;
#endif

  // Find the HALCON calibration plate and set the extracted points and contours in a calibration data model.
  void FindCalibObject(const HImage& Image, Hlong CameraIdx, Hlong CalibObjIdx, Hlong CalibObjPoseIdx, const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Remove observation data from a calibration data model.
  void RemoveCalibDataObserv(Hlong CameraIdx, Hlong CalibObjIdx, Hlong CalibObjPoseIdx) const;

  // Get contour-based observation data from a calibration data model.
  HXLDCont GetCalibDataObservContours(const HString& ContourName, Hlong CameraIdx, Hlong CalibObjIdx, Hlong CalibObjPoseIdx) const;

  // Get contour-based observation data from a calibration data model.
  HXLDCont GetCalibDataObservContours(const char* ContourName, Hlong CameraIdx, Hlong CalibObjIdx, Hlong CalibObjPoseIdx) const;

#ifdef _WIN32
  // Get contour-based observation data from a calibration data model.
  HXLDCont GetCalibDataObservContours(const wchar_t* ContourName, Hlong CameraIdx, Hlong CalibObjIdx, Hlong CalibObjPoseIdx) const;
#endif

  // Get observed calibration object poses from a calibration data model.
  HPose GetCalibDataObservPose(Hlong CameraIdx, Hlong CalibObjIdx, Hlong CalibObjPoseIdx) const;

  // Set observed calibration object poses in a calibration data model.
  void SetCalibDataObservPose(Hlong CameraIdx, Hlong CalibObjIdx, Hlong CalibObjPoseIdx, const HPose& ObjInCameraPose) const;

  // Get point-based observation data from a calibration data model.
  void GetCalibDataObservPoints(Hlong CameraIdx, Hlong CalibObjIdx, Hlong CalibObjPoseIdx, HTuple* Row, HTuple* Column, HTuple* Index, HTuple* Pose) const;

  // Set point-based observation data in a calibration data model.
  void SetCalibDataObservPoints(Hlong CameraIdx, Hlong CalibObjIdx, Hlong CalibObjPoseIdx, const HTuple& Row, const HTuple& Column, const HTuple& Index, const HTuple& Pose) const;

  // Query information about the relations between cameras, calibration objects, and calibration object poses.
  HTuple QueryCalibDataObservIndices(const HString& ItemType, Hlong ItemIdx, HTuple* Index2) const;

  // Query information about the relations between cameras, calibration objects, and calibration object poses.
  HTuple QueryCalibDataObservIndices(const char* ItemType, Hlong ItemIdx, HTuple* Index2) const;

#ifdef _WIN32
  // Query information about the relations between cameras, calibration objects, and calibration object poses.
  HTuple QueryCalibDataObservIndices(const wchar_t* ItemType, Hlong ItemIdx, HTuple* Index2) const;
#endif

  // Query data stored or computed in a calibration data model.
  HTuple GetCalibData(const HString& ItemType, const HTuple& ItemIdx, const HTuple& DataName) const;

  // Query data stored or computed in a calibration data model.
  HTuple GetCalibData(const HString& ItemType, Hlong ItemIdx, const HString& DataName) const;

  // Query data stored or computed in a calibration data model.
  HTuple GetCalibData(const char* ItemType, Hlong ItemIdx, const char* DataName) const;

#ifdef _WIN32
  // Query data stored or computed in a calibration data model.
  HTuple GetCalibData(const wchar_t* ItemType, Hlong ItemIdx, const wchar_t* DataName) const;
#endif

  // Define a calibration object in a calibration model.
  void SetCalibDataCalibObject(Hlong CalibObjIdx, const HTuple& CalibObjDescr) const;

  // Define a calibration object in a calibration model.
  void SetCalibDataCalibObject(Hlong CalibObjIdx, double CalibObjDescr) const;

  // Set type and initial parameters of a camera in a calibration data model.
  void SetCalibDataCamParam(const HTuple& CameraIdx, const HTuple& CameraType, const HCamPar& CameraParam) const;

  // Set type and initial parameters of a camera in a calibration data model.
  void SetCalibDataCamParam(const HTuple& CameraIdx, const HString& CameraType, const HCamPar& CameraParam) const;

  // Set type and initial parameters of a camera in a calibration data model.
  void SetCalibDataCamParam(const HTuple& CameraIdx, const char* CameraType, const HCamPar& CameraParam) const;

#ifdef _WIN32
  // Set type and initial parameters of a camera in a calibration data model.
  void SetCalibDataCamParam(const HTuple& CameraIdx, const wchar_t* CameraType, const HCamPar& CameraParam) const;
#endif

  // Create a HALCON calibration data model.
  void CreateCalibData(const HString& CalibSetup, Hlong NumCameras, Hlong NumCalibObjects);

  // Create a HALCON calibration data model.
  void CreateCalibData(const char* CalibSetup, Hlong NumCameras, Hlong NumCalibObjects);

#ifdef _WIN32
  // Create a HALCON calibration data model.
  void CreateCalibData(const wchar_t* CalibSetup, Hlong NumCameras, Hlong NumCalibObjects);
#endif

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HCalibData> HCalibDataArrayRef;
typedef HSmartPtr< HCalibDataArrayRef > HCalibDataArrayPtr;


// Represents multiple tool instances
class LIntExport HCalibDataArray : public HHandleBaseArray
{

public:

  // Create empty array
  HCalibDataArray();

  // Create array from native array of tool instances
  HCalibDataArray(const HCalibData* classes, Hlong length);

  // Copy constructor
  HCalibDataArray(const HCalibDataArray &tool_array);

  // Destructor
  virtual ~HCalibDataArray();

  // Assignment operator
  HCalibDataArray &operator=(const HCalibDataArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HCalibData* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HCalibDataArrayPtr *mArrayPtr;
};

}

#endif
