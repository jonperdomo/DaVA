#include "vtkHeelStatsInteractor.h"
#include <vtkObjectFactory.h>



vtkStandardNewMacro(vtkHeelStatsInteractor);

vtkHeelStatsInteractor::vtkHeelStatsInteractor(void)
{
}

vtkHeelStatsInteractor::~vtkHeelStatsInteractor(void)
{
}

void vtkHeelStatsInteractor::OnMouseWheelForward()
{
}

void vtkHeelStatsInteractor::MoveSliceForward()
{
}

void vtkHeelStatsInteractor::SetImageViewer(vtkImageViewer2* imageViewer)
{
	this->_ImageViewer = imageViewer;

}