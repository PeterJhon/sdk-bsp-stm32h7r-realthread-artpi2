/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/mjpeg_screen/MJPEGViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <videos/VideoDatabase.hpp>

MJPEGViewBase::MJPEGViewBase() :
    topbarBackButtonIsPressedCallback(this, &MJPEGViewBase::topbarBackButtonIsPressedCallbackHandler),
    videoIsDoneEndedCallback(this, &MJPEGViewBase::videoIsDoneEndedCallbackHandler),
    videoEndedCallback(this, &MJPEGViewBase::videoEndedCallbackHandler)
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

//    video.setPosition(0, 0, 800, 480);
//    video.setVideoData(video_ST8464_bin_start, video_ST8464_bin_length);
//    video.setRepeat(false);
//    video.play();
//    video.setMovieEndedAction(videoEndedCallback);
//    add(video);

    BlackScreen.setPosition(0, 0, 800, 480);
    BlackScreen.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(BlackScreen);

    topbar.setXY(0, 0);
    topbar.setBackButtonIsPressedCallback(topbarBackButtonIsPressedCallback);
    add(topbar);
}

MJPEGViewBase::~MJPEGViewBase()
{

}

void MJPEGViewBase::setupScreen()
{
    topbar.initialize();
}

void MJPEGViewBase::topbarBackButtonIsPressedCallbackHandler()
{
    //GoBackToMenu
    //When topbar backButtonIsPressed change screen to Menu
    //Go to Menu with screen transition towards West
    application().gotoMenuScreenWipeTransitionWest();
}

void MJPEGViewBase::videoEndedCallbackHandler(const touchgfx::VideoWidget& src)
{
    if (&src == &video)
    {
        //VideoIsDone
        //When video video ended fade BlackScreen
        //Fade BlackScreen to alpha:255 with CircIn easing in 500 ms (30 Ticks)
        BlackScreen.clearFadeAnimationEndedAction();
        BlackScreen.setFadeAnimationDelay(6);
        BlackScreen.startFadeAnimation(255, 30, touchgfx::EasingEquations::circEaseIn);
        BlackScreen.setFadeAnimationEndedAction(videoIsDoneEndedCallback);
    }
}

void MJPEGViewBase::afterTransition()
{
    //FadeBlackScreenAfterScreenTransitionIsDone
    //When screen transition ends fade BlackScreen
    //Fade BlackScreen to alpha:0 with ExpoOut easing in 500 ms (30 Ticks)
    BlackScreen.clearFadeAnimationEndedAction();
    BlackScreen.setFadeAnimationDelay(6);
    BlackScreen.startFadeAnimation(0, 30, touchgfx::EasingEquations::expoEaseOut);
}

void MJPEGViewBase::videoIsDoneEndedCallbackHandler(const touchgfx::FadeAnimator<touchgfx::Box>& comp)
{
    //PlayVideo
    //When VideoIsDone completed play video video
    //Play video on video
    video.play();


    //FadeBlackScreenAfterVideoIsDone
    //When VideoIsDone completed fade BlackScreen
    //Fade BlackScreen to alpha:0 with ExpoOut easing in 500 ms (30 Ticks)
    BlackScreen.clearFadeAnimationEndedAction();
    BlackScreen.setFadeAnimationDelay(6);
    BlackScreen.startFadeAnimation(0, 30, touchgfx::EasingEquations::expoEaseOut);

}
