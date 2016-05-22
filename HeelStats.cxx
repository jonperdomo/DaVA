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
 
  // Sphere
  vtkSmartPointer<vtkSphereSource> sphereSource = 
      vtkSmartPointer<vtkSphereSource>::New();
  sphereSource->Update();
  vtkSmartPointer<vtkPolyDataMapper> sphereMapper =
      vtkSmartPointer<vtkPolyDataMapper>::New();
  sphereMapper->SetInputConnection(sphereSource->GetOutputPort());
  vtkSmartPointer<vtkActor> sphereActor = 
      vtkSmartPointer<vtkActor>::New();
  sphereActor->SetMapper(sphereMapper);
  /*
  // VTK Renderer
  vtkSmartPointer<vtkRenderer> renderer = 
      vtkSmartPointer<vtkRenderer>::New();
  renderer->AddActor(sphereActor);
    // VTK/Qt wedded
  this->ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
  */
  // Signal for opening file
  connect(this->ui->pushButton, SIGNAL( clicked() ), this, SLOT( pushButtonClicked() ) );

  connect(this->ui->actionOpen_Data_Set, SIGNAL( triggered() ), this, SLOT( openDataSet() ) );  
  
}

void HeelStats::pushButtonClicked()
{
	cout << "Hello world" << endl;
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

  //Visualize
  /*
  vtkSmartPointer<vtkRenderer> renderer = 
      vtkSmartPointer<vtkRenderer>::New();

  this->ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
  */


  // Image style interactor for flipping through slices
  // Make own class where I create one


  // Image viewer
  vtkSmartPointer<vtkImageViewer2> imageViewer =
      vtkSmartPointer<vtkImageViewer2>::New();
  imageViewer->SetInputConnection( reader->GetOutputPort() );

  this->ui->qvtkWidget->SetRenderWindow( imageViewer->GetRenderWindow() );

  // Add signal to interactor for flipping slices
  vtkRenderWindowInteractor* interactor = this->ui->qvtkWidget->GetInteractor();

  vtkSmartPointer<vtkInteractorStyleImage> interactorStyle =
      vtkSmartPointer<vtkInteractorStyleImage>::New();

  //interactorStyle->SetImageViewer( imageViewer );

  imageViewer->SetupInteractor( interactor );

  interactor->SetInteractorStyle( interactorStyle );

  // Render image
  imageViewer->Render();
  //interactor->Start();

  /*
    // Map to volume
  vtkSmartPointer<vtkOpenGLGPUVolumeRayCastMapper> volumeMapper;
  volumeMapper->SetInputConnection( mi->GetOutputPort() );

  // Create volume
  vtkSmartPointer<vtkVolume> volume;
  volume->SetMapper( volumeMapper.GetPointer() );

  // Render
  vtkSmartPointer<vtkRenderer> renderer = 
      vtkSmartPointer<vtkRenderer>::New();
  renderer->AddVolume( volume.GetPointer() );
  this->ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
  */
}

void HeelStats::slotExit()
{
  qApp->exit();
}
