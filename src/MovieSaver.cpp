#include "MovieSaver.h"

#include "cinder/Utilities.h"

#include "Paths.h"

using namespace ci;
using namespace std;
using namespace reza::paths;

namespace reza {
namespace mov {
MovieSaver::MovieSaver( const ci::app::WindowRef &window )
	: mWindowRef( window )
{
}

MovieSaver::~MovieSaver()
{
}

void MovieSaver::save( const ci::fs::path &path, const std::string &filename, const std::string &extension )
{
	if( mRecording ) {
		return;
	}

	//auto format = qtime::MovieWriter::Format().codec(qtime::MovieWriter::JPEG).jpegQuality(1.0).fileType(qtime::MovieWriter::QUICK_TIME_MOVIE).averageBitsPerSecond(1000000000).defaultFrameDuration(1.0 / 60.0);
	//mMovieExporter = qtime::MovieWriter::create(addPath( addPath( path, filename ), extension, "." ), toPixels(mOutputWindowRef->getWidth()), toPixels(mOutputWindowRef->getHeight()), format);

	mRecording = true;
}

void MovieSaver::update()
{
	if( mCurrentFrame >= mTotalFrames ) {
		mCurrentFrame = 0;
	}
	mCurrentFrame++;
	mCurrentTime = float( mCurrentFrame ) / float( mTotalFrames );

	if( mRecording ) {
		int frameNumber = mCurrentFrame;
		if( frameNumber <= mTotalFrames ) {
			mProgress = float( frameNumber ) / float( mTotalFrames );
			//mMovieExporter->addFrame(copyWindowSurface());
		}
		if( frameNumber == mTotalFrames ) {
			//mMovieExporter->finish();
			//mMovieExporter.reset();
			mRecording = false;
			mProgress = 0.0f;
		}
	}
}
} // namespace mov
} // namespace reza