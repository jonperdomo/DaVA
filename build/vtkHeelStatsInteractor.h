#ifndef VTKHEELSTATSINTERACTOR_H
#define VTKHEELSTATSINTERACTOR_H

#include <vtkInteractionStyleModule.h>
#include <vtkInteractorStyleImage.h>

#include <vtkImageViewer2.h>

class vtkHeelStatsInteractor : public vtkInteractorStyleImage
{
public:
	static vtkHeelStatsInteractor* New();
	vtkTypeMacro( vtkHeelStatsInteractor, vtkInteractorStyleImage )

protected:
	vtkImageViewer2* _ImageViewer;
	int _Slice;
	int _MinSlice;
	int _MaxSlice;

public:
   void SetImageViewer(vtkImageViewer2* imageViewer);

protected:
	vtkHeelStatsInteractor(void);
	~vtkHeelStatsInteractor(void);

	void MoveSliceForward();
	virtual void OnMouseWheelForward();
};

#endif // VTKHEELSTATSINTERACTOR_H