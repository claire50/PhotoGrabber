/*****************************************************************
 * Copyright (c) 2004-2007,	Jan-Rixt Van Hoye					 *
 * All rights reserved.											 *
 * Distributed under the terms of the MIT License.               *
 *****************************************************************/

//
#ifndef STATWINDOW_H
#define STATWINDOW_H
//
// Includes
#include <View.h>
#include <Window.h>
#include <StatusBar.h>
//
// Local includes
#include "intf_global.h"
#include "MainWindow.h"
#include "Animation.h"

//
//		Status Window:: View
class BeCam_StatusView : public BView
{
public:
					BeCam_StatusView(BRect r,float xPos, float yPos, uint32 totalbytes, char *message);
					
	void			reset(uint32 totalbytes);
	void			updateStatus(uint32 delta, char *message);
	virtual void	Draw(BRect rect);
	Animation		*statusanimation;

private:
	char			msg[100];
	BStatusBar		*statusbar;	
	void 			CreateAnimation();
};
//
//		Status Window:: Status window Class
class BeCam_StatusWindow : public BWindow
{
public:
							BeCam_StatusWindow(float xPos,float yPos,uint32 totalbytes, char *message,class BeCam_MainWindow *mainWindow);

	virtual bool			QuitRequested();
	virtual void			MessageReceived(BMessage* message);
	void					reset(uint32 max);
	void					updateStatus(uint32 delta, char *message);
		
private:
	class BeCam_StatusView	*view;
	class BeCam_MainWindow  *parent;
};

#define STATUS_WINDOW				2
#define WINDOW_HEIGHT_STATUS		175
#define	WINDOW_WIDTH_STATUS			350

#endif

