/*
 * box.h
 *
 *  Created on: 5 Mar 2012
 *      Author: pwollaston
 */

#ifndef BOX_H_
#define BOX_H_

#include "textures.h"

#include <X11/Xlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_syswm.h>

#include <stdio.h>

class Box
{
public:
	Box();
	void Create(char btUID[128], char btMSRC[1024], int tStamp, GLuint TextureID, int bcol, int px, int py, int w, int h, int aw, int ah, int scale,
			int sourceType, int dScreen, char dAudio[16], bool hasHeader, bool hasSHeader, char txtHeader[256], char txtSHeader[256], int dbgLVL);
	void SwapTex(GLuint TextureID, int w, int h);
	bool doDraw(int  aOverride, ... );
	char * GetUID()
	{
		return bUID;
	}
	int GetTAlpha()
	{
		return tAlpha;
	}
	int GetTStamp()
	{
		return bTStamp;
	}
	void doUpdate();
	void rePos(int x, int y)
	{
		bX = x;
		bY = y;
	}
	bool isCreated()
	{
		return m_bRunning;
	}
	bool hasHeader()
	{
		return bHeaderEnab;
	}
	bool hasSHeader()
	{
		return sHeaderEnab;
	}
	char * txtHeader()
	{
		return bHeaderTxt;
	}
	char * txtSHeader()
	{
		return sHeaderTxt;
	}
	int width()
	{
		if (bType)
			return bW;
		else
			return bW;
	}
	int height()
	{
		if (bType)
			return 16 + bH;
		else
			return bH;
	}
	int scale()
	{
		return bScale;
	}
	int stype()
	{
		return sType;
	}
	void setType(int nt)
	{
		sType = nt;
	}
	int setSrc(char btMSrc[1024])
	{
		sprintf(bMSRC, "%s", btMSrc);
	}
	int audioOut(char btAO[16])
	{
		sprintf(audEnable, "%s", btAO);
	}
	int getScrollV()
	{
		return scrollv;
	}
	void setScrollV(int sv)
	{
		scrollv = sv;
	}
	int getClicks()
	{
		return tSTimer;
	}
	int getScreen()
	{
		return tCScreen;
	}
	void setClicks(int tClick)
	{
		tSTimer = tClick;
	}
	void setScreen(int tScreen)
	{
		tCScreen = tScreen;
	}
	char* buid()
	{
		return bUID;
	}
	void Destroy();
private:
	Texture layout[5];
	Texture ipBG;
	GLuint glTex;
	bool m_bRunning, bType, bHeaderEnab, sHeaderEnab;
	int bCol, bX, bY, bW, bH, bScale, sType, sWidth, sHeight, bTStamp, ipLFail, ipLooper, tAlpha, tSTimer, tCScreen, scrollv, ipCC, debugLevel;
	char bUID[128];
	char bMSRC[1024];
	char audEnable[16];
	char bHeaderTxt[256];
	char sHeaderTxt[256];

	void drawInfoBox(GLuint TextureID, bool bVis, int px, int py, int minx, int miny, int absh, float br, float bg, float bb, int scale, int balpha,
			int calpha);

	/* iPlayer Specific */
	bool ipVis;
	void createiPlayer(int maxqual, int width, int height, int x, int y, int scale);
	void createmPlayer(int width, int height, int x, int y, int scale);
	void destroy_x11_subwindow(Display *dpy, Window parent);
	Window create_x11_subwindow(Display *dpy, Window parent, int x, int y, int width, int height);
	Window create_sdl_x11_subwindow(int x, int y, int width, int height);
	SDL_SysWMinfo get_sdl_wm_info(void);
	void create_iplayer(const char *streamid, const char *quality, int cache, Window win, FILE **mplayer_fp);
	void create_mplayer(const char *streamid, Window win, FILE **mplayer_fp);

	/* MPlayer Integration */
	Window play_win;
	FILE *mplayer_fp;

	/* Generic */
	bool FileExists(const char* FileName);
};

#endif /* BOX_H_ */
