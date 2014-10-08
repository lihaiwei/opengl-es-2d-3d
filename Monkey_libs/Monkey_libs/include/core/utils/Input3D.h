//
//  Input3D.h
//  Monkey_libs
//
//  Created by Neil on 4/10/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#ifndef Monkey_libs_Input3D_h
#define Monkey_libs_Input3D_h

#include "platform/PlatformMacros.h"
#include "core/base/Object.h"

#include <vector>

NS_MONKEY_BEGIN

class Input3D : public Object {
    
public:
    
    static const unsigned int A = 65;
    static const unsigned int B = 66;
    static const unsigned int C = 67;
    static const unsigned int D = 68;
    static const unsigned int E = 69;
    static const unsigned int F = 70;
    static const unsigned int G = 71;
    static const unsigned int H = 72;
    static const unsigned int I = 73;
    static const unsigned int J = 74;
    static const unsigned int K = 75;
    static const unsigned int L = 76;
    static const unsigned int M = 77;
    static const unsigned int N = 78;
    static const unsigned int O = 79;
    static const unsigned int P = 80;
    static const unsigned int Q = 81;
    static const unsigned int R = 82;
    static const unsigned int S = 83;
    static const unsigned int T = 84;
    static const unsigned int U = 85;
    static const unsigned int V = 86;
    static const unsigned int W = 87;
    static const unsigned int X = 88;
    static const unsigned int Y = 89;
    static const unsigned int Z = 90;
    static const unsigned int ALTERNATE = 18;
    static const unsigned int BACKQUOTE = 192;
    static const unsigned int BACKSLASH = 220;
    static const unsigned int BACKSPACE = 8;
    static const unsigned int CAPS_LOCK = 20;
    static const unsigned int COMMA = 188;
    static const unsigned int COMMAND = 19;
    static const unsigned int CONTROL = 17;
    static const unsigned int DELETE = 46;
    static const unsigned int DOWN = 40;
    static const unsigned int END = 35;
    static const unsigned int ENTER = 13;
    static const unsigned int EQUAL = 187;
    static const unsigned int ESCAPE = 27;
    static const unsigned int F1 = 112;
    static const unsigned int F10 = 121;
    static const unsigned int F11 = 122;
    static const unsigned int F12 = 123;
    static const unsigned int F13 = 124;
    static const unsigned int F14 = 125;
    static const unsigned int F15 = 126;
    static const unsigned int F2 = 113;
    static const unsigned int F3 = 114;
    static const unsigned int F4 = 115;
    static const unsigned int F5 = 116;
    static const unsigned int F6 = 117;
    static const unsigned int F7 = 118;
    static const unsigned int F8 = 119;
    static const unsigned int F9 = 120;
    static const unsigned int HOME = 36;
    static const unsigned int INSERT = 45;
    static const unsigned int LEFT = 37;
    static const unsigned int LEFTBRACKET = 219;
    static const unsigned int MINUS = 189;
    static const unsigned int NUMBER_0 = 48;
    static const unsigned int NUMBER_1 = 49;
    static const unsigned int NUMBER_2 = 50;
    static const unsigned int NUMBER_3 = 51;
    static const unsigned int NUMBER_4 = 52;
    static const unsigned int NUMBER_5 = 53;
    static const unsigned int NUMBER_6 = 54;
    static const unsigned int NUMBER_7 = 55;
    static const unsigned int NUMBER_8 = 56;
    static const unsigned int NUMBER_9 = 57;
    static const unsigned int NUMPAD = 21;
    static const unsigned int NUMPAD_0 = 96;
    static const unsigned int NUMPAD_1 = 97;
    static const unsigned int NUMPAD_2 = 98;
    static const unsigned int NUMPAD_3 = 99;
    static const unsigned int NUMPAD_4 = 100;
    static const unsigned int NUMPAD_5 = 101;
    static const unsigned int NUMPAD_6 = 102;
    static const unsigned int NUMPAD_7 = 103;
    static const unsigned int NUMPAD_8 = 104;
    static const unsigned int NUMPAD_9 = 105;
    static const unsigned int NUMPAD_ADD = 107;
    static const unsigned int NUMPAD_DECIMAL = 110;
    static const unsigned int NUMPAD_DIVIDE = 111;
    static const unsigned int NUMPAD_ENTER = 108;
    static const unsigned int NUMPAD_MULTIPLY = 106;
    static const unsigned int NUMPAD_SUBTRACT = 109;
    static const unsigned int PAGE_DOWN = 34;
    static const unsigned int PAGE_UP = 33;
    static const unsigned int PERIOD = 190;
    static const unsigned int QUOTE = 222;
    static const unsigned int RIGHT = 39;
    static const unsigned int RIGHTBRACKET = 221;
    static const unsigned int SEMICOLON = 186;
    static const unsigned int SHIFT = 16;
    static const unsigned int SLASH = 191;
    static const unsigned int SPACE = 32;
    static const unsigned int TAB = 9;
    static const unsigned int UP = 38;
    
private:
    
    static std::vector<unsigned int> _ups;
    static std::vector<unsigned int> _downs;
    static std::vector<unsigned int> _hits;
    static int _keyCode;
    static float _deltaX;
    static float _deltaY;
    static int _deltaMove;
    static int _mouseUp;
    static int _mouseHit;
    static int _mouseDown;
    static int _rightMouseUp;
    static int _rightMouseHit;
    static int _rightMouseDown;
    static int _middleMouseUp;
    static int _middleMouseHit;
    static int _middleMouseDown;
    static int _mouseDoubleClick;
    static float _mouseX;
    static float _mouseY;
    static float _stageX;
    static float _stageY;
    static float _mouseXSpeed;
    static float _mouseYSpeed;
    static bool  _mouseUpdated;
    static int   _currFrame;
    static float _movementX;
    static float _movementY;
    
public:
    
    
    /**
     *  mouse move
     *  @param xs  x坐标
     *  @param ys  y坐标
     *  @param num 数量
     */
    static void mouseMove(float* xs, float* ys, int num);
    /**
     *  mouse up
     *
     *  @param xs  x坐标
     *  @param ys  y坐标
     *  @param num 数量
     */
    static void mouseUP(float* xs, float* ys, int num);
    /**
     *  mouse Down
     *
     *  @param xs  x坐标
     *  @param ys  y坐标
     *  @param num 数量
     */
    static void mouseDown(float* xs, float* ys, int num);
    /**
     *  mouse wheel
     *  @param deltaX
     *  @param deltaY
     */
    static void mouseWheel(float deltaX, float deltaY);
    /**
     *  right mouse down
     *
     *  @param xs  x坐标
     *  @param ys  y坐标
     *  @param num 数量
     */
    static void rightMouseDown(float* xs, float* ys, int num);
    /**
     *  right mouse up
     *  @param xs  x坐标
     *  @param ys  y坐标
     *  @param num 数量
     */
    static void rightMouseUp(float* xs, float* ys, int num);
    /**
     *  millde mouse down
     *  @param xs  x坐标
     *  @param ys  y坐标
     *  @param num 数量
     */
    static void middleMouseDown(float* xs, float* ys, int num);
    /**
     *  middle mouse up
     *  @param xs  x坐标
     *  @param ys  y坐标
     *  @param num 数量
     */
    static void middleMouseUp(float* xs, float* ys, int num);
    /**
     *  double click
     *
     *  @param xs  x坐标
     *  @param ys  y坐标
     *  @param num 数量
     */
    static void doubleClick(float* xs, float* ys, int num);
    /**
     *  key down
     *  @param keycode 键code
     */
    static void keyDown(int keycode);
    /**
     *  key up
     *  @param keycode
     */
    static void keyUp(int keycode);
    /**
     *  get key code
     *  @return
     */
    static int getKeycode();
    /**
     *  检测键是否被按下
     *  @param keycode
     *  @return
     */
    static bool isKeydown(int keycode);
    /**
     *  检测键是否被松开
     *  @param keycode
     *  @return
     */
    static bool isKeyUp(int keycode);
    /**
     *  @param keycode
     *  @return
     */
    static bool isKeyHit(int keycode);
    /**
     *  是否双击
     *  @return
     */
    static bool isMouseDoubleClick();
    /**
     *  get mouse wheel delta
     *  @return
     */
    static float getDeltaX();
    /**
     *  get mouse wheel delta
     *  @return
     */
    static float getDeltaY();
    /**
     *  get mouse y speed
     *  @return
     */
    static float getMouseYSpeed();
    /**
     *  get mouse x speed
     *  @return
     */
    static float getMouseXSpeed();
    /**
     *  @return
     */
    static bool isMouseHit();
    /**
     *  检测mouse是否松开
     *  @return
     */
    static bool isMouseUP();
    /**
     *  检测mouse是否按下
     *  @return
     */
    static bool isMouseDown();
    /**
     *  检测右键是否点击
     *  @return
     */
    static bool isRightMouseHit();
    /**
     *  检测右键是否按下
     *  @return
     */
    static bool isRightMouseDown();
    /**
     *  检测右键是否松开
     *  @return
     */
    static bool isRightMouseUp();
    /**
     *  检测是否点击中键
     *  @return
     */
    static bool isMiddleMouseHit();
    /**
     *  中键up
     *  @return
     */
    static bool isMiddleMouseUp();
    /**
     *  中键down
     *  @return
     */
    static bool isMiddleMouseDown();
    /**
     *  获取x坐标
     *  @return
     */
    static float getMouseX();
    /**
     *  获取y坐标
     *  @return
     */
    static float getMouseY();
    /**
     *  @return
     */
    static float getMovementX();
    /**
     *  @return
     */
    static float getMovementY();
    /**
     *  clear
     */
    static void clear();
    
    static void update();
    
};


NS_MONKEY_END

#endif
