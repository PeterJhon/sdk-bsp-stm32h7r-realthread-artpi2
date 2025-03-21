/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/WaffleMenuIconBase.hpp>
#include <images/BitmapDatabase.hpp>
#include <touchgfx/Color.hpp>

WaffleMenuIconBase::WaffleMenuIconBase() :
    IconIsPressedCallback(0),
    flexButtonCallback(this, &WaffleMenuIconBase::flexButtonCallbackHandler),
    scaleIconDownEndedCallback(this, &WaffleMenuIconBase::scaleIconDownEndedCallbackHandler),
    scaleIconBackToNormalEndedCallback(this, &WaffleMenuIconBase::scaleIconBackToNormalEndedCallbackHandler)
{
    setWidth(65);
    setHeight(100);
    icon.setXY(0, 0);
    icon.setBitmap(touchgfx::Bitmap(BITMAP_WAFFLE_MENU_CONE_LARGE_ID));
    icon.setWidth(65);
    icon.setHeight(100);
    icon.setBitmapPosition(2.0f, 2.0f);
    icon.setScale(0.9f);
    icon.setCameraDistance(1000.0f);
    icon.setOrigo(32.5f, 50.0f, 1000.0f);
    icon.setCamera(32.5f, 50.0f);
    icon.setAngles(0.0f, 0.0f, 6.3f);
    icon.setRenderingAlgorithm(touchgfx::TextureMapper::BILINEAR_INTERPOLATION);
    add(icon);

    clickListener.setBoxWithBorderPosition(0, 0, 50, 50);
    clickListener.setBorderSize(5);
    clickListener.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    clickListener.setAlpha(0);
    clickListener.setAction(flexButtonCallback);
    clickListener.setPosition(0, 0, 65, 100);
    add(clickListener);
}

WaffleMenuIconBase::~WaffleMenuIconBase()
{

}

void WaffleMenuIconBase::initialize()
{

}

void WaffleMenuIconBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &clickListener)
    {
        //scaleIconDown
        //When clickListener clicked scale icon
        //Scale icon
        icon.setupAnimation(touchgfx::AnimationTextureMapper::SCALE, 0.700f, 6, 0, touchgfx::EasingEquations::quartEaseInOut);
        icon.startAnimation();
        icon.setTextureMapperAnimationEndedAction(scaleIconDownEndedCallback);
    }
}

void WaffleMenuIconBase::scaleIconDownEndedCallbackHandler(const touchgfx::AnimationTextureMapper& comp)
{
    //scaleIconBackToNormal
    //When scaleIconDown completed scale icon
    //Scale icon
    icon.setupAnimation(touchgfx::AnimationTextureMapper::SCALE, 0.900f, 6, 0, touchgfx::EasingEquations::quintEaseInOut);
    icon.startAnimation();
    icon.setTextureMapperAnimationEndedAction(scaleIconBackToNormalEndedCallback);

}

void WaffleMenuIconBase::scaleIconBackToNormalEndedCallbackHandler(const touchgfx::AnimationTextureMapper& comp)
{
    //EmitIconIsPressed
    //When scaleIconBackToNormal completed emit IconIsPressed callback
    //Emit callback
    emitIconIsPressedCallback();

}
