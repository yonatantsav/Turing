#ifndef _TEST_APP
#define _TEST_APP

//#define USE_IR // Uncomment this to use infra red instead of RGB cam...

#include "ofxOpenNI.h"
#include "ofMain.h"
#include "ofxCv.h"
#include "ofxFaceTracker.h"
#include "ofxQTKitAVScreenRecorder.h" 
using namespace ofxCv;
using namespace cv;


class testApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void exit();

	void	setupRecording(string _filename = "");
	void	setupPlayback(string _filename);
	string	generateFileName();

	bool				isLive, isTracking, isRecording, isCloud, isCPBkgnd, isMasking;
	bool				isTrackingHands, isFiltering;

	ofxOpenNIContext	recordContext, playContext;
	ofxDepthGenerator	recordDepth, playDepth;

#ifdef USE_IR
	ofxIRGenerator		recordImage, playImage;
#else
	ofxImageGenerator	recordImage, playImage;
#endif

	ofxHandGenerator	recordHandTracker, playHandTracker;

	ofxUserGenerator	recordUser, playUser;
	ofxOpenNIRecorder	oniRecorder;
    

    
    ofxLimb leftHand, rightHand, neck;
    

    

#if defined (TARGET_OSX) //|| defined(TARGET_LINUX) // only working on Mac/Linux at the moment (but on Linux you need to run as sudo...)
	ofxHardwareDriver	hardware;
#endif

	void				drawMasks();
	void				drawPointCloud(ofxUserGenerator * user_generator, int userID);
    ofPoint                centermass(ofxUserGenerator * user_generator, int userID);

	int					nearThreshold, farThreshold;
	int					pointCloudRotationY;

	ofImage				allUserMasks, user1Mask, user2Mask, depthRangeMask;

	float				filterFactor;

        ofImage img;
    
///
    
    
    ofxFaceTracker tracker;
	ofVec2f position;
	float scale;
	ofVec3f orientation;
	ofMatrix4x4 rotationMatrix;
	
	Mat translation, rotation;
	ofMatrix4x4 pose;
    
    ofPolyline leftEye;
        ofPolyline fullFace;

    ofRectangle faceBox;
// CAMERA:
//    ofVideoGrabber cam;

    
//RECORDING VIDEO:
    
    ofFbo fboSaver;
    ofPixels fboPixels;
    ofxQTKitAVScreenRecorder recorder; 

    //WEBCAM
    ofxQTKitVideoGrabber grabber;

    
};

#endif
