/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 21.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HTEXTMODEL
#define HCPP_HTEXTMODEL

namespace HalconCpp
{

// Represents an instance of a text model for text segmentation.
class LIntExport HTextModel : public HHandle
{

public:

  // Copy constructor
  HTextModel(const HTextModel& source) : HHandle(source) {}

  // Copy constructor
  HTextModel(const HHandle& handle);

  // Create HTextModel from handle, taking ownership
  explicit HTextModel(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('text_model')!
  virtual void AssertType(Hphandle handle) const;

public:



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // create_text_model_reader: Create a text model.
  explicit HTextModel(const HString& Mode, const HTuple& OCRClassifier);

  // create_text_model_reader: Create a text model.
  explicit HTextModel(const HString& Mode, const HString& OCRClassifier);

  // create_text_model_reader: Create a text model.
  explicit HTextModel(const char* Mode, const char* OCRClassifier);

#ifdef _WIN32
  // create_text_model_reader: Create a text model.
  explicit HTextModel(const wchar_t* Mode, const wchar_t* OCRClassifier);
#endif

  // create_text_model: Create a text model.
  explicit HTextModel();




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Find text in an image.
  HTextResult FindText(const HImage& Image) const;

  // Query parameters of a text model.
  HTuple GetTextModelParam(const HString& GenParamName) const;

  // Query parameters of a text model.
  HTuple GetTextModelParam(const char* GenParamName) const;

#ifdef _WIN32
  // Query parameters of a text model.
  HTuple GetTextModelParam(const wchar_t* GenParamName) const;
#endif

  // Set parameters of a text model.
  void SetTextModelParam(const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Set parameters of a text model.
  void SetTextModelParam(const HString& GenParamName, Hlong GenParamValue) const;

  // Set parameters of a text model.
  void SetTextModelParam(const char* GenParamName, Hlong GenParamValue) const;

#ifdef _WIN32
  // Set parameters of a text model.
  void SetTextModelParam(const wchar_t* GenParamName, Hlong GenParamValue) const;
#endif

  // Clear a text model.
  static void ClearTextModel(const HTextModelArray& TextModel);

  // Clear a text model.
  void ClearTextModel() const;

  // Create a text model.
  void CreateTextModelReader(const HString& Mode, const HTuple& OCRClassifier);

  // Create a text model.
  void CreateTextModelReader(const HString& Mode, const HString& OCRClassifier);

  // Create a text model.
  void CreateTextModelReader(const char* Mode, const char* OCRClassifier);

#ifdef _WIN32
  // Create a text model.
  void CreateTextModelReader(const wchar_t* Mode, const wchar_t* OCRClassifier);
#endif

  // Create a text model.
  void CreateTextModel();

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HTextModel> HTextModelArrayRef;
typedef HSmartPtr< HTextModelArrayRef > HTextModelArrayPtr;


// Represents multiple tool instances
class LIntExport HTextModelArray : public HHandleBaseArray
{

public:

  // Create empty array
  HTextModelArray();

  // Create array from native array of tool instances
  HTextModelArray(const HTextModel* classes, Hlong length);

  // Copy constructor
  HTextModelArray(const HTextModelArray &tool_array);

  // Destructor
  virtual ~HTextModelArray();

  // Assignment operator
  HTextModelArray &operator=(const HTextModelArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HTextModel* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HTextModelArrayPtr *mArrayPtr;
};

}

#endif
