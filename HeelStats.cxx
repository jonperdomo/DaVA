#include "HeelStats.h"

// This is included here because it is forward declared in
// HeelStats.h
#include "ui_HeelStats.h"

#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSphereSource.h>
#include <vtkSmartPointer.h>
//
#include <iostream>
#include <sstream>

#include <QFileDialog>
#include <QString>
//
#include <vtkImageViewer2.h>
#include <vtkDICOMImageReader.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>

#include <QPixmap>
#include <QIcon>
#include <QStringList>
#include  <QTableWidgetItem>

// For volume
#include <vtkImageData.h>
#include <vtkVolumeProperty.h>
#include <vtkMatrix4x4.h>
#include <vtkGPUVolumeRayCastMapper.h>
#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>
#include <vtkAxesActor.h>

using namespace std;

// Constructor
HeelStats::HeelStats()
{
  this->ui = new Ui_HeelStats;
  this->ui->setupUi(this);

  QPixmap pix( "C:/Users/jperdomo/code/HeelStats/Icons/HS-Logo.PNG" );
  QIcon icon( pix );
  this->setWindowIcon( icon );

  // Set Image Viewer, Interactor
  imageViewer = vtkSmartPointer<vtkImageViewer2>::New();

  // Update slice orientation
  imageViewer->SetSliceOrientationToXY();
  interactorStyle = vtkSmartPointer<vtkInteractorStyleImage>::New();

  // Add renderer
  vtkSmartPointer<vtkRenderer> renderer = 
      vtkSmartPointer<vtkRenderer>::New();
  renderer->SetBackground( 0, 0, 0 );

  this->ui->qvtkWidget->GetRenderWindow()->AddRenderer( renderer );

  /*
  // Set interactor style to interactor
  vtkRenderWindowInteractor* interactor = this->ui->qvtkWidget->GetInteractor();
  interactor->SetInteractorStyle( interactorStyle );
  */

  // Disable slider and table until image is loaded
  this->ui->verticalSlider->hide();	

  // Connect signals and slots
  connect(this->ui->pushButton, SIGNAL( clicked() ), this, SLOT( pushButtonClicked() ) );
  connect(this->ui->actionOpen_Data_Set, SIGNAL( triggered() ), this, SLOT( openDataSet() ) );
  connect(this->ui->verticalSlider, SIGNAL( valueChanged(int) ), this, SLOT( updateSlice() ) );

}

void HeelStats::pushButtonClicked()
{
	cout << "Hello world" << endl;
}

void HeelStats::updateImageSlice()
{
  int _MinSlice;
  int _MaxSlice;
  int _Slice;
  if ( ! ( this->ui->verticalSlider->isHidden() ) )
  {
	  _MinSlice = imageViewer->GetSliceMin();
	  _MaxSlice = imageViewer->GetSliceMax();
	  _Slice = this->ui->verticalSlider->value();
	  cout << "Slicer: Min = " << _MinSlice << ", Max = " << _MaxSlice << ", Current pos = " << _Slice << std::endl;
  }
}

void HeelStats::updateSlice()
{
  int _Slice;
  if ( ! ( this->ui->verticalSlider->isHidden() ) )
  {
	  _Slice = this->ui->verticalSlider->value();
	  imageViewer->SetSlice( _Slice );
	  imageViewer->Render();
  }
}

void HeelStats::openDataSet()
{
  QString fileName;
  fileName = QFileDialog::getExistingDirectory( this, tr("Open Local Data Set"), "C:/Users/jperdomo", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks );
  // Convert QString to std::string
  std::string fileStd = fileName.toStdString();
  cout << "Data set opened: " << fileStd << endl;

  const char * fileChar = fileStd.c_str();
  
  // Read data set
  vtkSmartPointer<vtkDICOMImageReader> reader =
      vtkSmartPointer<vtkDICOMImageReader>::New();
  reader->SetDirectoryName( fileChar );
  reader->Update();
  
  /*
  // Set input to ImageViewer
  imageViewer->SetInputConnection( reader->GetOutputPort() );

  // Set the render window from the ImageViewer
  this->ui->qvtkWidget->SetRenderWindow( imageViewer->GetRenderWindow() );

  // Add signal to interactor for flipping slices
  vtkRenderWindowInteractor* interactor = this->ui->qvtkWidget->GetInteractor();

  // Set interactor for ImageViewer
  imageViewer->SetupInteractor( interactor );

  // Render image
  imageViewer->Render();

  // Update slider properties
  this->ui->verticalSlider->setMinimum( imageViewer->GetSliceMin() );
  this->ui->verticalSlider->setMaximum( imageViewer->GetSliceMax() );
  this->ui->verticalSlider->show();
  */

  // Initialize table for displaying statistics
  QTableWidget *statsTable = this->ui->tableWidget;
  statsTable->setRowCount( 6 );
  statsTable->setColumnCount( 1 );

  // Create header labels
  QStringList verticalLabels;
  verticalLabels << "Study ID:" << "Directory:" << "Extension:" << "Width:" << "Height:" << "Pixel spacing:";
  statsTable->setVerticalHeaderLabels( verticalLabels );

  // Study ID
  QTableWidgetItem *studyID = new QTableWidgetItem( reader->GetStudyID() );
  statsTable->setItem( 0, 0, studyID );

  // Directory
  QTableWidgetItem *fullPath = new QTableWidgetItem( reader->GetDirectoryName() );
  statsTable->setItem( 0, 1, fullPath );

  // Extension
  QTableWidgetItem *fileExtensions = new QTableWidgetItem( reader->GetFileExtensions() );
  statsTable->setItem( 0, 2, fileExtensions );

  // Width
  stringstream wStream;
  wStream << ( reader->GetWidth() );
  std::string wString = wStream.str();
  const char *wChar = wString.c_str();
  QTableWidgetItem *width = new QTableWidgetItem( wChar );
  statsTable->setItem( 0, 3, width );

  // Height
  stringstream hStream;
  hStream << ( reader->GetHeight() );
  std::string hString = hStream.str();
  const char *hChar = hString.c_str();
  QTableWidgetItem *height = new QTableWidgetItem( hChar );
  statsTable->setItem( 0, 4, height );

  //
  // Volume rendering section below
  //

  // Create volume
  vtkSmartPointer<vtkImageData> volumeData =
      vtkSmartPointer<vtkImageData>::New();

  // Copy image data
  volumeData->DeepCopy( reader->GetOutput() );

  // Ray cast data
  vtkSmartPointer<vtkGPUVolumeRayCastMapper> volumeMapper =
	  vtkSmartPointer<vtkGPUVolumeRayCastMapper>::New();
  volumeMapper->SetInputData( volumeData );

  vtkSmartPointer<vtkVolumeProperty> volumeProperty =
  vtkSmartPointer<vtkVolumeProperty>::New();
 
  vtkSmartPointer<vtkPiecewiseFunction> compositeOpacity =
  vtkSmartPointer<vtkPiecewiseFunction>::New();
  compositeOpacity->AddPoint(0.0,0.1);
  compositeOpacity->AddPoint(80.0,0.2);
  compositeOpacity->AddPoint(255.0,0.1);
  volumeProperty->SetScalarOpacity(compositeOpacity);
 
  vtkSmartPointer<vtkColorTransferFunction> color =
  vtkSmartPointer<vtkColorTransferFunction>::New();
  color->AddRGBPoint(0.0  ,0.0,0.0,1.0);
  color->AddRGBPoint(40.0  ,1.0,0.0,0.0);
  color->AddRGBPoint(255.0,1.0,1.0,1.0);
  volumeProperty->SetColor(color);
 
  vtkSmartPointer<vtkVolume> volume =
  vtkSmartPointer<vtkVolume>::New();
  volume->SetMapper(volumeMapper);
  volume->SetProperty(volumeProperty);

  // VTK Renderer
  vtkSmartPointer<vtkRenderer> renderer = 
      vtkSmartPointer<vtkRenderer>::New();
  renderer->SetBackground(0.5f,0.5f,1.0f);

  //vtkSmartPointer<vtkRenderWindowInteractor> iren =
     // vtkSmartPointer<vtkRenderWindowInteractor>::New();
  vtkRenderWindow *renWin = this->ui->qvtkWidget->GetRenderWindow();

  renWin->AddRenderer( renderer );
  renWin->SetSize(1280,1024);

  //iren->SetRenderWindow( renWin );

  // Add coordinate system axes, so we have a reference for position and orientation
  vtkSmartPointer<vtkAxesActor> axes = vtkSmartPointer<vtkAxesActor>::New();
  axes->SetTotalLength(250,250,250);
  axes->SetShaftTypeToCylinder();
  axes->SetCylinderRadius(0.01);
  renderer->AddActor(axes);

  renderer->AddVolume( volume );
  renWin->Render();
  //iren->Start();
}

void HeelStats::slotExit()
{
  qApp->exit();
}
