#ifndef POSTCALIBRATION_H
#define POSTCALIBRATION_H

class CWorkspace;
class StackSettings;
class CAllStackingTasks;
class QAction;
class QMenu;

#include <QWidget>

#include "DSSCommon.h"
#include "StackingTasks.h"

namespace Ui {
class PostCalibration;
}

class PostCalibration : public QWidget
{
    Q_OBJECT

typedef QWidget
		Inherited;
public:
    explicit PostCalibration(QWidget *parent = nullptr);
    ~PostCalibration();

public slots:
	void onSetActive();

private:
    Ui::PostCalibration *ui;
	std::unique_ptr<CWorkspace> workspace;
	StackSettings *		pStackSettings;
	CPostCalibrationSettings pcs;
	CAllStackingTasks *	pStackingTasks;
	QAction * onMedian;
	QAction * onGaussian;
	QMenu   * replacementMenu;
	PostCalibration & createActions();
	PostCalibration & createMenus();
	PostCalibration & setReplacementMethod(int);


private slots:
	void on_cleanHotPixels_toggled(bool);
	void on_hotFilter_valueChanged(int);
	void on_hotThreshold_valueChanged(int);

	void on_cleanColdPixels_toggled(bool);
	void on_coldFilter_valueChanged(int);
	void on_coldThreshold_valueChanged(int);

	void on_replacementMethod_clicked();
	void on_saveDeltaImage_toggled(bool);
};

#endif // POSTCALIBRATION_H
