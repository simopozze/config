/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int gappx = 6; /* gap pixel between windows */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { "Iosevka NFM:size=13" };
static const char dmenufont[]       = "Iosevka NFM:size=13";

// Colors
static const char col_gray_light[]  = "#2d2a2e";
static const char col_gray_dark[]   = "#221f22";
static const char col_special[]     = "#fc9867";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray_light, col_gray_dark, col_gray_dark},
	[SchemeSel]  = { col_gray_dark, col_special,  col_special },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
    { "Gimp",     NULL,       NULL,       0,            1,           -1 }
};

/* layout(s) */
static const float mfact     = 0.2; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]  = 
{
	  "rofi", "-show", "drun", "-font", "Iosevka NFM", "12", "-icon-theme", "Papirus", "-show-icons", NULL 
}; 

static const char *browser[]    = { "firefox", NULL };
static const char *i3lock[]     = { "i3lock","-c","#000000", NULL };
static const char *termcmd[]    = { "alacritty", NULL};

static const char *vol_u[]	= {"pactl", "set-sink-volume" ,"0", "+5%", NULL};
static const char *vol_d[] 	= {"pactl", "set-sink-volume" ,"0", "-5%", NULL};
static const char *vol_m[] 	= {"pactl", "set-sink-mute", "0", "toggle", NULL};
static const char *mic_m[] 	= {"pactl", "set-source-mute", "1", "toggle", NULL};

static const char *fm[]     = {"pcmanfm", NULL};
//
// Brightness
#define BRIGHT_SCRIPT_PATH "/home/$USER/.config/dwm/scripts/brightness.sh"

static Key keys[] = {
	/* modifier                    key        function        argument */
	{ MODKEY,                     	XK_s,      spawn,          {.v = browser  } },
	{ MODKEY,                       XK_r,      spawn,          {.v = i3lock   } },
	{ MODKEY,   					XK_a,	   spawn,		   {.v = dmenucmd } },
	{ MODKEY,  	               		XK_space,  spawn,          {.v = termcmd  } },
	{ MODKEY,						XK_e,      spawn,          {.v = fm       } },

    // SPECIAL FN
    // Volume
	{ 0,				            XK_F1,     spawn,          {.v = vol_m } },
	{ 0,				            XK_F2,     spawn,          {.v = vol_d } },
	{ 0,				            XK_F3,     spawn,          {.v = vol_u } },
	{ 0,				            XK_F4,     spawn,          {.v = mic_m } },

    // Brightness
	{ 0,				            XK_F5,     spawn,           SHCMD(BRIGHT_SCRIPT_PATH" -dec") },
	{ 0,				            XK_F6,     spawn,           SHCMD(BRIGHT_SCRIPT_PATH" -inc") },

	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_Return, setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_c,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
