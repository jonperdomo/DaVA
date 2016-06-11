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
#include <string>
#include <iostream>
#include <QFileDialog>
#include <QString>
//
#include <vtkImageViewer2.h>
#include <vtkDICOMImageReader.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>

using namespace std;

// Constructor
HeelStats::HeelStats() 
{
  this->ui = new Ui_HeelStats;
  this->ui->setupUi(this);

  // Set Image Viewer, Interactor
  imageViewer = vtkSmartPointer<vtkImageViewer2>::New();
  interactorStyle = vtkSmartPointer<vtkInteractorStyleImage>::New();

  // Add renderer
  vtkSmartPointer<vtkRenderer> renderer = 
      vtkSmartPointer<vtkRenderer>::New();
  renderer->SetBackground( 0, 0, 0 );

  this->ui->qvtkWidget->GetRenderWindow()->AddRenderer( renderer );

  // Set interactor style to interactor
  vtkRenderWindowInteractor* interactor = this->ui->qvtkWidget->GetInteractor();
  interactor->SetInteractorStyle( interactorStyle );

  // Disable slider until image is loaded
  this->ui->verticalSlider->hide();

  // Signal for opening file
  connect(this->ui->pushButton, SIGNAL( clicked() ), this, SLOT( pushButtonClicked() ) );

  connect(this->ui->actionOpen_Data_Set, SIGNAL( triggered() ), this, SLOT( openDataSet() ) );

  //connect(this->ui->verticalSlider, SIGNAL( sliderReleased() ), this, SLOT( updateImageSlice() ) );

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
}

void HeelStats::slotExit()
{
  qApp->exit();
}
