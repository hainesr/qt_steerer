/*----------------------------------------------------------------------------
    ControlForm class header file for QT steerer GUI. 

    (C)Copyright 2002 The University of Manchester, United Kingdom,
    all rights reserved.

    This software is produced by the Supercomputing, Visualization &
    e-Science Group, Manchester Computing, the Victoria University of
    Manchester as part of the RealityGrid project.

    This software has been tested with care but is not guaranteed for
    any particular purpose. Neither the authors, nor the University of
    Manchester offer any warranties or representations, nor do they
    accept any liabilities with respect to this software.

    This program must not be used for commmercial gain without the
    written permission of the authors.
    
    Supercomputing, Visualization & e-Science Group
    Manchester Computing
    University of Manchester
    Manchester M13 9PL

    email:  csar-advice@cfs.ac.uk.
    Tel:    +44 161 275 6824/5997
    Fax:    +44 161 275 6040    
    
    Date          Version    Updates                            Author
    ----          -------    -------                            ------
    03.10.2002      0.1                                         S Ramsden

---------------------------------------------------------------------------*/

#ifndef __CONTROL_FORM_H__
#define __CONTROL_FORM_H__

#include <qgroupbox.h>
#include <qlabel.h>
#include <qvbox.h>
#include <qwidget.h>

class QPushButton;
class QString;
class QHBoxLayout;

class Application;
class ParameterTable;
class SteeredParameterTable;
class IOTypeTable;

class ControlForm : public QWidget 
{
  Q_OBJECT

public:

  ControlForm(QWidget *aParent, const char *aName, int aSimHandle, Application *aApplication);
  ~ControlForm();

  void updateParameters();
  void updateIOTypes();

  void disableAll();
  void disableIOCmdButtons();
  void enableIOCmdButtons();

  void setStatusLabel(const char *aStatusText);

private:
  void updateParameters(bool aSteeredFlag);
  void disableButtons();
  
  void emitAllIOCommands(const int aAdditionalCmd = -1, bool aForceEmitFlag = false);
  void emitAll(const int aAdditionalCmd = -1);


protected slots:
  void enableParamButtonsSlot();    
  void enableSampleButtonsSlot();   
  void enableChkPtButtonsSlot();
  void emitAllValuesSlot();
  void emitAllIOCommandsSlot();
  void emitAllSlot();
  void emitAllAndDetachCmdSlot();



signals:
  void detachFromApplicationForErrorSignal();

private:
  int			mSimHandle;		

  QLabel		*mStatusLabel;

  QPushButton		*mEmitButton;

  QPushButton		*mSndSampleButton;
  QPushButton		*mSetSampleFreqButton;

  QPushButton		*mSndChkPtButton;
  QPushButton		*mSetChkPtFreqButton;

  QPushButton		*mEmitAllValuesButton;
  QPushButton		*mEmitAllIOCommandsButton;
  QPushButton		*mEmitAllButton;

  ParameterTable	*mMonParamTable;
  SteeredParameterTable	*mSteerParamTable;
  IOTypeTable		*mIOTypeSampleTable;
  IOTypeTable		*mIOTypeChkPtTable;

};


#endif


