#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	this->frame_image.allocate(720,720, OF_IMAGE_COLOR);
	this->frame = cv::Mat(720, 720, CV_MAKETYPE(CV_8UC3, this->frame_image.getPixels().getNumChannels()), this->frame_image.getPixels().getData(), 0);
}

//--------------------------------------------------------------
void ofApp::update() {
	float noise_value_r, noise_value_g, noise_value_b;
	float r, g, b;

	for (int x = 0; x < 720; x++) {
		for (int y = 0; y < 720; y++) {
			r = 255 * ofNoise(x * 0.0025, y * 0.0025, (ofGetFrameNum() + 0)  * 0.05);
			g = 255 * ofNoise(x * 0.0025, y * 0.0025, (ofGetFrameNum() + 15) * 0.05);
			b = 255 * ofNoise(x * 0.0025, y * 0.0025, (ofGetFrameNum() + 30) * 0.05);
	
			this->frame.at<cv::Vec3b>(x, y) = cv::Vec3b(r, g, b);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	
	this->frame_image.update();
	this->frame_image.draw(0, 0);
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}