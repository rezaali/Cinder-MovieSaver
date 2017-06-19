/*
Copyright(c) 2017 Reza Ali syed.reza.ali@gmail.com www.syedrezaali.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <functional>
#include <string>

#include "cinder/Camera.h"
#include "cinder/Filesystem.h"
#include "cinder/app/Window.h"

#include "glm/glm.hpp"

namespace reza {
namespace mov {
typedef std::shared_ptr<class MovieSaver> MovieSaverRef;
class MovieSaver {
  public:
	static MovieSaverRef create( const ci::app::WindowRef &window )
	{
		return MovieSaverRef( new MovieSaver( window ) );
	}
	virtual ~MovieSaver();

	void update();

	void save( const ci::fs::path &path, const std::string &filename, const std::string &extension );

	bool isRecording() { return mRecording; }
	float getProgress() { return mProgress; }
	float getCurrentTime() { return mCurrentTime; }

	void setTotalFrames( int totalframes ) { mTotalFrames = totalframes; }
	int getTotalFrames() { return mTotalFrames; }

  protected:
	MovieSaver( const ci::app::WindowRef &window );

	ci::app::WindowRef mWindowRef = nullptr;
	int mTotalFrames = 120;
	int mCurrentFrame = 0;
	float mCurrentTime = 0;
	float mProgress = 0.0f;
	bool mRecording = false;
	ci::fs::path mSaveMoviePath;
	std::string mSaveMovieName;
	std::string mSaveMovieExtension;

	//qtime::MovieWriterRef mMovieExporter;
};
} // namespace mov
} // namespace reza