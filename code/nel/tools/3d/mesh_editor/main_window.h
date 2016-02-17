// NeL - MMORPG Framework <http://dev.ryzom.com/projects/nel/>
// Copyright (C) 2010  Winch Gate Property Limited
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef NLQT_MAIN_WINDOW_H
#define NLQT_MAIN_WINDOW_H
#include <nel/misc/types_nl.h>

// STL includes

// Qt includes
#include <QMainWindow>

// NeL includes
#include <nel/misc/rgba.h>
#include <nel/misc/ucstring.h>
#include <nel/misc/time_nl.h>
#include <nel/3d/animation_time.h>
#include <nel/net/login_cookie.h>

// Project includes
#include "configuration.h"
#include "sound_utilities.h"

class QTreeView;
class QDirModel;
class QUndoStack;
class QScrollArea;
class QTimer;

namespace NLMISC {
	class CConfigFile;
}

namespace NL3D {
	class UDriver;
	class UScene;
	class UTextContext;
	class UVisualCollisionManager;
}

namespace NLPACS {
	class UMoveContainer;
	class UGlobalRetriever;
}

namespace NLSOUND {
	class UAudioMixer;
	class CSoundAnimManager;
}

namespace NLQT {
	class CCommandLogDisplayer;
	class CErrorList;
}

class CGraphicsViewport;
class CGraphicsConfig;

/**
 * CMainWindow
 * \brief CMainWindow
 * \date 2010-02-05 13:01GMT
 * \author Jan Boon (Kaetemi)
 */
class CMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	CMainWindow(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	virtual ~CMainWindow();

	virtual void setVisible(bool visible);

private slots:
	void applyGraphicsConfig();
	// void applySoundConfig();

	void about();
	void updateRender();
	void printDebug();

protected:
	virtual void closeEvent(QCloseEvent *e);

private:
	void updateInitialization(bool visible);

	void initProjectConfig(const std::string &asset);

	void createActions();
	void translateActions();
	void createMenus();
	void translateMenus();
	void createToolBars();
	void translateToolBars();
	void createStatusBar();
	void createDockWindows();
	void translateDockWindows();

	void recalculateMinimumWidth();

	void cfcbSoundEnabled(NLMISC::CConfigFile::CVar &var);

	void cfcbLanguageCode(NLMISC::CConfigFile::CVar &var);

private:
	CMainWindow(const CMainWindow &);
	CMainWindow &operator=(const CMainWindow &);

private:
	CConfiguration m_Configuration;
	CSoundUtilities m_SoundUtilities;

	QUndoStack *m_UndoStack;

	bool m_IsExiting;
	bool m_IsGraphicsInitialized, m_IsGraphicsEnabled;
	bool m_IsSoundInitialized, m_IsSoundEnabled;

	QTimer *m_Timer;
	CGraphicsViewport *m_GraphicsViewport;

	NLQT::CCommandLogDisplayer *m_CommandLog;
	QDockWidget *m_CommandLogDock;

	NLQT::CErrorList *m_ErrorList;
	QDockWidget *m_ErrorListDock;

	CGraphicsConfig *m_GraphicsConfig;
	QScrollArea *m_GraphicsConfigScroll;
	QDockWidget *m_GraphicsConfigDock;

	QTreeView *m_AssetTreeView;
	QDirModel *m_AssetTreeModel;
	QDockWidget *m_AssetTreeDock;
	
	QMenu *m_FileMenu;
	QMenu *m_EditMenu;
	QMenu *m_ViewportMenu;
	QMenu *m_WidgetsMenu;
	QMenu *m_HelpMenu;

	QToolBar *m_FileToolBar;
	QToolBar *m_EditToolBar;

	QAction *m_AboutAct;
	QAction *m_QuitAct;
	QAction *m_PrintDebugAct;
	QAction *m_UndoAct;
	QAction *m_RedoAct;
	QAction *m_SaveScreenshotAct;

	//NLMISC::CConfigFile *ConfigFile; // owned by CConfiguration
	//CLoadingScreen LoadingScreen; // owned by CLoading (special case, always available)
	//NL3D::UDriver *Driver; // owned by CGraphics
	//NL3D::UTextContext *TextContext; // owned by CGraphics
	//NLSOUND::UAudioMixer *AudioMixer; // owned by CSound
	//NLSOUND::CSoundAnimManager *SoundAnimManager; // owned by CSound
	//THCOMMON::CSheetLoader *SheetLoader; // owned by initSheets and releaseSheets
	//NL3D::UScene *Scene; // owned by CEnvironment
	//NLPACS::UMoveContainer *MoveContainer; // owned by CEnvironment
	//NLPACS::UGlobalRetriever *GlobalRetriever; /// The global retriever used for pacs // owned by CEnvironment
	//NL3D::UVisualCollisionManager *VisualCollisionManager; /// The collision manager for ground snapping // owned by CEnvironment
	//THCLIENT::CKeyBinder *KeyBinder; // owned by CInterface

	//NLMISC::TLocalTime LocalTime; // use for delta only // owned by CGameTime
	//NLMISC::TLocalTime LocalTimeDelta; // owned by CGameTime
	//NL3D::TGlobalAnimationTime AnimationTime; // owned by CGameTime
	//NL3D::TAnimationTime AnimationTimeDelta; // owned by CGameTime
	//float FramesPerSecond; // owned by CGameTime
	//float FramesPerSecondSmooth; // owned by CGameTime

	//NLMISC::CVector DetailTargetPosition; // player or camera position for lod improvements // owned by camera

}; /* class CMainWindow */

#endif /* #ifndef NLQT_MAIN_WINDOW_H */

/* end of file */
