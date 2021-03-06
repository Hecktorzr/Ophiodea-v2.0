#pragma once

#include "ofMain.h"
#include "OphiodeaConstants.h"

#define DEMO_MODE
#define USE_OPENCV

// we can remove #ifdefs after opencv added to linux version
#ifdef USE_OPENCV
#include "ofxOpenCv.h"
#endif

class testApp : public ofBaseApp{
	public:

		void setup();
		void update();
		void draw();
        void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);



        // Our own variables

        ofVideoGrabber videoGrabber[kNUMBER_OF_CAMERAS];
        ofPixels pixelsFromCamera[kNUMBER_OF_CAMERAS];
        ofPixels pixelsForOutput;
        ofPixels pixelsForTopImage;
        ofPixels pixelsForBottomImage;
        ofPixels previosPixelsForOutput;


        ofSerial serialManager;

        int halfTheNumberOfCameras;

        int outputImageWidth;
        int outputImageHeight;

        double halfOutputImageWidth;
        double halfOutputImageHeight;

        double amountOfMovement;

        int isMotorRunning;

        int imageWidthWithoutBlendingArea;
        int imageHeightWithoutBlendingArea;

		bool bUseShaderRender;
		ofFbo fbo;
		ofShader circleShader;

		bool bUseMask;
		ofImage maskImg;
		int camsStarted;

        time_t timeSinceLastActivation;
        time_t timeSinceLastPause;
		
		#ifdef USE_OPENCV
			ofxCvColorImage			colorImgLarge;
			ofxCvColorImage			colorImg;
			ofxCvGrayscaleImage 	grayImage;
			ofxCvGrayscaleImage 	grayBg;
			ofxCvGrayscaleImage 	grayDiff;
			float amountMoveBlend;
		#endif
		
		bool bShowControls;
		
		// Our own functions

        void updateALLtheCaptures();
        void placeCapturedImagesOnScreen();
        void drawVerticalAlphaComposites();
        void drawHorizontalAlphaComposites();
        void applySphereTransformation();
        void calculateAmountOfMovement();
        double distanceBetweenTwoPoints(float x1, float y1, float z1, float x2, float y2, float z2);

		// shader render
		void renderWithShader();
		void calculateMovmementForShader();

        void startTheMotor();
        void stopTheMotor();
        void scheduleMotorStop();

		void startNextCamera(); // remove?
		
		void generateMaskImage();

};
