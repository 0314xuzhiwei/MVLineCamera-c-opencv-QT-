/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 21.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HGENERICSHAPEMODELRESULT
#define HCPP_HGENERICSHAPEMODELRESULT

namespace HalconCpp
{

// Represents an instance of a result of generic shape matching.
class LIntExport HGenericShapeModelResult : public HHandle
{

public:

  // Create an uninitialized instance
  HGenericShapeModelResult():HHandle() {}

  // Copy constructor
  HGenericShapeModelResult(const HGenericShapeModelResult& source) : HHandle(source) {}

  // Copy constructor
  HGenericShapeModelResult(const HHandle& handle);

  // Create HGenericShapeModelResult from handle, taking ownership
  explicit HGenericShapeModelResult(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('generic_shape_model_result')!
  virtual void AssertType(Hphandle handle) const;

public:




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Find the best matches of one or multiple shape models in an image.
  Hlong FindGenericShapeModel(const HObject& SearchImage, const HShapeModelArray& ModelID);

  // Find the best matches of one or multiple shape models in an image.
  Hlong FindGenericShapeModel(const HObject& SearchImage, const HShapeModel& ModelID);

  // Get alphanumerical values from a shape matching result.
  HTuple GetGenericShapeModelResult(const HTuple& MatchSelector, const HString& GenParamName) const;

  // Get alphanumerical values from a shape matching result.
  HTuple GetGenericShapeModelResult(const HTuple& MatchSelector, const char* GenParamName) const;

#ifdef _WIN32
  // Get alphanumerical values from a shape matching result.
  HTuple GetGenericShapeModelResult(const HTuple& MatchSelector, const wchar_t* GenParamName) const;
#endif

  // Get objects from a shape matching result.
  HObject GetGenericShapeModelResultObject(const HTuple& MatchSelector, const HString& GenParamName) const;

  // Get objects from a shape matching result.
  HObject GetGenericShapeModelResultObject(const HTuple& MatchSelector, const char* GenParamName) const;

#ifdef _WIN32
  // Get objects from a shape matching result.
  HObject GetGenericShapeModelResultObject(const HTuple& MatchSelector, const wchar_t* GenParamName) const;
#endif

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HGenericShapeModelResult> HGenericShapeModelResultArrayRef;
typedef HSmartPtr< HGenericShapeModelResultArrayRef > HGenericShapeModelResultArrayPtr;


// Represents multiple tool instances
class LIntExport HGenericShapeModelResultArray : public HHandleBaseArray
{

public:

  // Create empty array
  HGenericShapeModelResultArray();

  // Create array from native array of tool instances
  HGenericShapeModelResultArray(const HGenericShapeModelResult* classes, Hlong length);

  // Copy constructor
  HGenericShapeModelResultArray(const HGenericShapeModelResultArray &tool_array);

  // Destructor
  virtual ~HGenericShapeModelResultArray();

  // Assignment operator
  HGenericShapeModelResultArray &operator=(const HGenericShapeModelResultArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HGenericShapeModelResult* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HGenericShapeModelResultArrayPtr *mArrayPtr;
};

}

#endif
