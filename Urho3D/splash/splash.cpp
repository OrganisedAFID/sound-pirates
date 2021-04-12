/**
 * @file splash.cpp
 * Creates a splash screen
 */


/************************************************************************/
/*!

//

// Copyright (c) 2008-2020 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
*/
/************************************************************************/

#include "RtAudio.h"
#include <fftw3.h>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <cstring>
#include <stdio.h>
#include <SFML/Audio.hpp>
#include <vector>

#include <complex>     
#include <string>
#include "audioIn.h"
#include "fft.h"
#include "playNote.h"
#include "instructionsStatements.h"
#include "processBuffer.h"
#include "defineNote.h"
#include <alsa/asoundlib.h>


#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

#include <string>
#include <memory>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <poll.h>
#include <thread>
#include <chrono>
#include <signal.h>


#include <Urho3D/Urho3D.h>
#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Graphics/RenderPath.h>
#include <Urho3D/Engine/Application.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Input/InputEvents.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Resource/XMLFile.h>
#include <Urho3D/IO/Log.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/UI/Text.h>
#include <Urho3D/UI/Font.h>
#include <Urho3D/UI/Button.h>
#include <Urho3D/UI/UIEvents.h>
#include <Urho3D/UI/Window.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/SceneEvents.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Graphics/Geometry.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Graphics/DebugRenderer.h>
#include <Urho3D/Graphics/Octree.h>
#include <Urho3D/Graphics/Light.h>
#include <Urho3D/Graphics/Model.h>
#include <Urho3D/Graphics/StaticModel.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/Graphics/Skybox.h>
#include <Urho3D/Graphics/Zone.h>
#include <Urho3D/Audio/Sound.h>
#include <Urho3D/Audio/SoundSource3D.h>
#include <Urho3D/Audio/SoundListener.h>
#include <Urho3D/Audio/Audio.h>
#include <Urho3D/Graphics/ParticleEmitter.h>
#include <Urho3D/Graphics/ParticleEffect.h>
#include <Urho3D/Graphics/Terrain.h>

#include <Urho3D/Physics/CollisionShape.h>
#include <Urho3D/Physics/Constraint.h>

#include <Urho3D/Physics/RigidBody.h>

#include "splash.h"
#include <Urho3D/DebugNew.h>


/**
 * 
 * global variables list to be incorporated in setup
 */
int a = 0;
std::vector<double> v;
int pipefds[2];
int freqMax;  
std::vector<double> window;
const int bandNumber = 128;
unsigned int sampleRate = 44100;
unsigned int bufferFrames = 4410; // 512 sample frames
volatile sig_atomic_t stop;
char note_to_write;


/**
 * inthand function allows close of terminal with ctrl C
 * 
 */

void inthand(int signum) {
    stop = 1;
return;
}

/**
 * processBuffer fuction. Calls fft, takes output of fft and sorts max freq into note to report
 * output freqMax
 * called by record
 * 
 */
int processBuffer()
{
    ::freqMax;
    ::pipefds[2];

    std::vector<double> output;
    fft(window, output);

    freqMax = 0;
    int freqMaxIndex = 51;
    int amplitudeThreshold = 10000;

    for (int i = 51; i < 100; i++)
    {
        if (output[i] > output[freqMaxIndex] && output[i] > amplitudeThreshold)
        {
            freqMaxIndex = i;
            freqMax = i * 44100.0 / window.size();
        }


    } 
    note_to_write = define_note(freqMax); 
       
    if(note_to_write  != 'N'){
    write(pipefds[1], note_to_write + "4", sizeof(note_to_write  + "4"));
}
else{
    write(pipefds[1], "None", sizeof("None"));
    }
    
    std::cout << freqMax << std::endl;

    return freqMax, pipefds[2];
}

/**
 * record function. Activate the audio input and write to buffer
 * called by audioIn
 *  
 */

int record(void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
           double streamTime, RtAudioStreamStatus status, void *userData)
{
    printf("Called Record \n");
    if (status)
    {
        std::cout << "Stream overflow detected!" << std::endl;
    }

    int i = 0;
    signed short *a = (signed short *)inputBuffer;

    //Add nBufferFrames values from the input buffer into window
    while (window.size() < nBufferFrames * 2 && i < nBufferFrames)
    {
        window.push_back(a[i++]);
    }

    processBuffer();

    if (window.size() == nBufferFrames * 2)
    {
        //get rid of the first half of window
        window.erase(window.begin(), window.begin() + nBufferFrames);
    }

    return 0;
}




/**
 * audioIn function. 
 * calls record, which calls processBuffer,which calls fft
 * called by URHO3D_DEFINE_APPLICATION_MAIN(HelloWorld)
 * 
 */
int audioIn()
{    
    snd_pcm_t * _soundDevice;
    snd_pcm_hw_params_t *hw_params;
    //access audio device
    RtAudio adc;
    int err = snd_pcm_open( &_soundDevice, "plughw:0,0", SND_PCM_STREAM_PLAYBACK, 0 );
    //if (adc.getDeviceCount() < 1) {
    if (err < 1) {

        std::cout << "No audio devices found!\n";
        return -1;
    }
    
    

    //Print device infos
    unsigned int numDev = adc.getDeviceCount();
    RtAudio::DeviceInfo di;
    for (unsigned int i = 0; i < numDev; ++i)
    {
        // use the Debugger if you need to know deviceID
        std::cout << "Device info" << std::endl;
        di = adc.getDeviceInfo(i);
        //std::cout << di << std::endl;
        
    }

    //Set parameters
    RtAudio::StreamParameters parameters;
    parameters.deviceId = adc.getDefaultInputDevice();
    parameters.nChannels = 1;
    parameters.firstChannel = 0;

    std::thread t1(instructionsStatements);
    t1.join();

    try
    {
        //Calls the record function
        adc.openStream(NULL, &parameters, RTAUDIO_SINT16, sampleRate, &bufferFrames, &record);
        adc.startStream();
        std::cout << adc.getVersion();
    }
    catch (RtAudioError &e)
    {
        e.printMessage();
        return -1;
    }

    char input;
    std::cout << "\nRecording ... press <enter> to quit.\n";

    
    signal(SIGINT, inthand);
    stop = 0;
    while(!stop){}
    adc.closeStream();
    return 0;
}


/**
 * Main program. Starts the Urho program setup, opens pipe and sets state machine in motion
 * 
 */
URHO3D_DEFINE_APPLICATION_MAIN(GameSys)

/** 
 * GameSys function. instigates pipeline, checks and returns error if unable
 * starts game process
 * calls audioIn function and playNote function
 * 
 */ 
GameSys::GameSys(Context* context) :
    Sample(context)
{   
    ::pipefds[2];
    int returnstatus;
    int pid;
    returnstatus = pipe(pipefds);
    if (returnstatus == -1)
    {
        printf("Unable to create pipe\n");
        return;
    }
    pid = fork();
    //Game process
    if (pid == 0)
    {
    }
    //SP process
    else
    {
        engine_->Exit();

        audioIn();
        playNote();   
    }
}
/**
 * Start function. Executes base class startup, creates the title scene 
 * and accepts mouse input 
 * 
 */
void GameSys::Start()
{   
    // Execute base class startup
    Sample::Start();


    // Create title scene
    CreateTitleScene();


    // Set the mouse mode to use in the sample
    Sample::InitMouseMode(MM_FREE);
    
return;
}



/**
 * CreateTitleScene function. Start screen splash, with button
 * calls CreateText, provides text content, calls Subscribe to events to allow input for state change
 * 
 */
void GameSys::CreateTitleScene()
{
    auto *ui = GetSubsystem<UI>();
    UIElement *root = ui->GetRoot();
    auto *cache = GetSubsystem<ResourceCache>();
    // Load the style sheet from xml
    root->SetDefaultStyle(cache->GetResource<XMLFile>("UI/DefaultStyle.xml"));

    auto* startButton = 
    CreateButton(root, "StartButton", "StartText", "Start Game!", 250, 500);
    auto* insButton = 
    CreateButton(root, "InsButton", "InsText", "Instructions", 600, 500);
    auto* helloText = 
    CreateText("Welcome to Sound Pirates!", "welcomeText", 300, 300);
    SubscribeToEvent(startButton, E_CLICK, URHO3D_HANDLER(GameSys, HandleStartClick));
    SubscribeToEvent(insButton, E_CLICK, URHO3D_HANDLER(GameSys, HandleInsClick));
}
/**
 * CreateText function. Defines text parameters font (optional), colour, position
 * returns text
 * 
 */
Text* GameSys::CreateText(String content, String tagName, int x, int y, String fontText)
{  
    auto* cache = GetSubsystem<ResourceCache>();
    Urho3D::Font* font = cache->GetResource<Font>(fontText);
    // Construct new Text object
    SharedPtr<Text> text(new Text(context_));

    // Set String to display
    text->SetText(content);

    // Set font and text color
    text->SetFont(font, 30);
    text->SetColor(Color(0.0f, 10.0f, 1.0f));
    text->SetPosition(IntVector2(x, y));
    text->AddTag(tagName);

    // Add Text instance to the UI root element
    GetSubsystem<UI>()->GetRoot()->AddChild(text);
    return text;
}

/**
 * Creates a button on the given root, with the given tag.
 * It also adds a text to the button given a name with txtName, and a content with txtCont.
 * It will place the button according to x and y coordinates.
 * Possible hAlign values = HA_LEFT, HA_CENTER, HA_RIGHT, HA_CUSTOM
 * Possible vAlign values =  VA_TOP = 0, VA_CENTER, VA_BOTTOM, VA_CUSTOM 
 * 

 */ 
Button* GameSys::CreateButton
(UIElement* root, String tag, String txtName, String txtCont, 
  int x, int y, int width)
{
    auto *b = new Button(context_);

    root->AddChild(b);
    // Reference a style from the style sheet loaded earlier:
    b->SetStyleAuto();

    b->SetWidth(width);

    b->AddTag(tag);
    b->SetPosition(IntVector2(x, y));

    // Set the layout mode to make the child text elements aligned vertically
    b->SetLayout(LM_VERTICAL, 20, {40, 40, 40, 40});

    // Add text
    b->CreateChild<Text>(txtName)->SetStyleAuto();
    auto *t = b->GetChildStaticCast<Text>(txtName, false);
    t->SetText(txtCont);
    t->SetHorizontalAlignment(HA_CENTER);

    return b;
}
/**
 * SubscribeToEvents function. Takes described events as inputs to change state
 * 
 */
void GameSys::SubscribeToEvents()
{
    // Subscribe HandleUpdate() function for processing update events

    SubscribeToEvent(E_UPDATE, URHO3D_HANDLER(GameSys, HandleUpdate));
    
}
/**
 * 
 * 
 */
void GameSys::HandleUpdate(StringHash eventType, VariantMap& eventData)
{
    using namespace Update;

    // Take the frame time step, which is stored as a float
    float timeStep = eventData[P_TIMESTEP].GetFloat();
    float MOVE_SPEED=30.0f;
    int i;

    //framecount_++;
    time_+=timeStep;

    std::cout << "Note played: " << OutputNote << "\n";

    PODVector<Urho3D::Node*> ship = scene_->GetChildrenWithTag("ship");
    Vector3 shipPos = ship[0]->GetPosition();
    Node* shipNode = ship[0];

    int fd = ::pipefds[0];
    struct pollfd *fds;
    fds = (pollfd *)calloc(1, sizeof(pollfd));
    fds[0].fd = fd;
    fds[0].events |= POLLIN;
    int rv = poll(fds, 1, 0);

    if (rv == -1)
    {
        printf("An error occurred: %d\n", errno);
        return;
    }

    if (rv == 1)
    {
        printf("Events occurred: %d.", rv);
        char readmessage[20];
        read(::pipefds[0], readmessage, sizeof(readmessage));
        printf("Child Process - Reading from pipe – Message 1 is %s\n", readmessage);
        //ChangeTexts(readmessage);

        UIElement *root = GetSubsystem<UI>()->GetRoot();
        auto *cache = GetSubsystem<ResourceCache>();
        auto* ui = GetSubsystem<UI>();

        String notes[8] = {"C4", "D4", "E4", "F4", "G4", "A4", "B4", "None"};
                
            float timeStep = eventData[P_TIMESTEP].GetFloat();
            float MOVE_SPEED=30.0f;
            int i;
            playNote();

            if ( readmessage[20] == OutputNote ){
                std::cout << "You played the correct note\n";
                shipNode->Translate(Vector3(0.0f, -4.0f, 30.0f)*timeStep*MOVE_SPEED);
                shipNode->SetScale(Vector3(0.2f, 0.2f, 0.2));
                // Construct new Text object, set string to display and font to use
                auto* feedback = ui->GetRoot()->CreateChild<Text>();
                feedback->SetText(
                    "You played the CORRECT note"
                );
                feedback->SetFont(cache->GetResource<Font>("Fonts/Anonymous Pro.ttf"), 20);

                // Position the text relative to the screen center
                feedback->SetHorizontalAlignment(HA_CENTER);
                feedback->SetVerticalAlignment(VA_CENTER);
                feedback->SetPosition(0, ui->GetRoot()->GetHeight() / 4);
                    
            }
            else if ( readmessage[20] != OutputNote ){
                shipNode->Translate(Vector3(0.0f, -30.0f, .0f)*timeStep*MOVE_SPEED);
                shipNode->SetScale(Vector3(0.2f, 0.2f, 0.2));
                SharedPtr<Text> feedback2_;
                feedback2_=new Text(context_);
                // Text will be updated later in the E_UPDATE handler. Keep readin'.
                feedback2_->SetText("You played an INCORRECT note");
                // If the engine cannot find the font, it comes with Urho3D.
                // Set the environment variables URHO3D_HOME, URHO3D_PREFIX_PATH or
                // change the engine parameter "ResourcePrefixPath" in the Setup method.
                feedback2_->SetFont(cache->GetResource<Font>("Fonts/Anonymous Pro.ttf"),20);
                feedback2_->SetColor(Color(.3,0,.3));
                feedback2_->SetHorizontalAlignment(HA_CENTER);
                feedback2_->SetVerticalAlignment(VA_CENTER);
                GetSubsystem<UI>()->GetRoot()->AddChild(feedback2_);
                std::cout << "You played the INCORRECT note\n";

            }
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        

    }
}
/**
 * 
 * 
 */
void GameSys::ChangeTexts(String note)
{

    UIElement *root = GetSubsystem<UI>()->GetRoot();
    auto *cache = GetSubsystem<ResourceCache>();

    String notes[8] = {"C4", "D4", "E4", "F4", "G4", "A4", "B4", "None"};
    
        std::cout << "Note played: " << OutputNote << "\n";
    

    // Make relevant note more opaque and all others less opaque
    
}

/** 
 * when you click on the start button, the second scene appears
 * 
 */

void GameSys::HandleStartClick(StringHash eventType, VariantMap& eventData)
{
    using namespace Click;
      
    DeleteTitleScene();
    //Show the main game screen
    CreateMainScene();
    SetupViewport();

    // Finally subscribe to the update event so we can move the camera.

    SubscribeToEvents();    
}

/** 
 * when you click on the instructions button, the instructions appear
 * 
 */
void GameSys::HandleInsClick(StringHash eventType, VariantMap& eventData)
{
    using namespace Click;
      
    DeleteTitleScene();
    printf("Deleted title scene");

    //Show the instructions
    CreateInstructionsScene();
}

/**
 * Shows the instruction text onto the screen
 */
void GameSys::CreateInstructionsScene()
{
    UIElement* root = GetSubsystem<UI>()->GetRoot();
    auto* backButton = 
    CreateButton(root, "BackButton", "BackText", "Back to title screen", 400, 500);   
    auto* instructionsText = CreateText("Instruction text goes here", "Instructions", 0, 0);
    SubscribeToEvent(backButton, E_CLICK, URHO3D_HANDLER(GameSys, HandleBackClick));
}

/** 
 * when you click on the back button, the instructions dissappear 
 * and the title screen comes back
 * 
 */
void GameSys::HandleBackClick(StringHash eventType, VariantMap& eventData)
{
    using namespace Click;

    //Delete the instructions
    DeleteInstructionsScene();

    //Create the title scene again
    CreateTitleScene();
}

/**
 * Deletes the instructions scene
 * 
 */
void GameSys::DeleteInstructionsScene()
{
    UIElement* root = GetSubsystem<UI>()->GetRoot();
    
    // erase instruction text
    Urho3D::PODVector<Urho3D::UIElement*> insText = root->GetChildrenWithTag("Instructions");
    insText[0]->Remove();
    
    // erase back button
    Urho3D::PODVector<Urho3D::UIElement*> backButton = root->GetChildrenWithTag("BackButton");
    backButton[0]->Remove();
}

/**
 * Deletes the first scene
 * 
 */
void GameSys::DeleteTitleScene()
{
    UIElement *root = GetSubsystem<UI>()->GetRoot();
    auto *cache = GetSubsystem<ResourceCache>();


    Urho3D::PODVector<Urho3D::UIElement*> welcomeText = root->GetChildrenWithTag("welcomeText");
    welcomeText[0]->Remove();
    
    // erase start button
    Urho3D::PODVector<Urho3D::UIElement*> startButton = root->GetChildrenWithTag("StartButton");
    startButton[0]->Remove();

    // erase instructions button
    Urho3D::PODVector<Urho3D::UIElement*> insButton = root->GetChildrenWithTag("InsButton");
    insButton[0]->Remove();
}

/**
 * Creates the scene with the ship
 * 
 * 

 */ 
void GameSys::CreateMainScene()
{
    auto *cache = GetSubsystem<ResourceCache>();
    scene_ = new Scene(context_);


    /** Create the Octree component to the scene. This is required before adding any drawable components, or else nothing will
     * show up. The default octree volume will be from (-1000, -1000, -1000) to (1000, 1000, 1000) in world coordinates; it
     * is also legal to place objects outside the volume but their visibility can then not be checked in a hierarchically
     * optimizing manner
     */
    scene_->CreateComponent<Octree>();
    

    Node *planeNode = CreatePlane();
    Node *zoneNode = scene_->CreateChild("Zone");
    auto *zone = zoneNode->CreateComponent<Zone>();
    zone->SetBoundingBox(BoundingBox(-1000.0f, 1000.0f));
    zone->SetAmbientColor(Color(0.15f, 0.15f, 0.15f));
    zone->SetFogColor(Color(0.2f, 0.2f, 0.2f));
    zone->SetFogStart(300.0f);
    zone->SetFogEnd(500.0f);
    Node *shipNode = CreateShip();
    shipNode->AddTag("ship");

     Node* skyNode = scene_->CreateChild("Sky");
    skyNode->SetScale(500.0f); // The scale actually does not matter
    auto* skybox = skyNode->CreateComponent<Skybox>();
    skybox->SetModel(cache->GetResource<Model>("Models/Box.mdl"));
    skybox->SetMaterial(cache->GetResource<Material>("Materials/Skybox.xml"));

    // Create a directional light to the world so that we can see something. The light scene node's orientation controls the
    // light direction; we will use the SetDirection() function which calculates the orientation from a forward direction vector.
    // The light will use default settings (white light, no shadows)
            // Create a red directional light (sun)
        
            Node* lightNode=scene_->CreateChild();
            lightNode->SetDirection(Vector3::FORWARD);
            lightNode->Yaw(50);     // horizontal
            lightNode->Pitch(10);   // vertical
            Light* light=lightNode->CreateComponent<Light>();
            light->SetLightType(LIGHT_DIRECTIONAL);
            light->SetBrightness(3);
            light->SetColor(Color(1.0,.6,0.3,1));
            light->SetCastShadows(true);
        
        
    /*Node *lightNode = scene_->CreateChild("DirectionalLight");
    lightNode->SetDirection(Vector3(0.9f, -1.0f, 0.6f)); // The direction vector does not need to be normalized
    auto *light = lightNode->CreateComponent<Light>();
    light->SetLightType(LIGHT_DIRECTIONAL);*/

    // Create a scene node for the camera, which we will move around
    // The camera will use default settings (1000 far clip distance, 45 degrees FOV, set aspect ratio automatically)
    cameraNode_ = scene_->CreateChild("Camera");
    cameraNode_->CreateComponent<Camera>();

    // Set an initial position for the camera scene node above the plane
   // cameraNode_->SetRotation(Quaternion(0.0f, 450.0f, 0.0f));
    cameraNode_->SetPosition(Vector3(0.0f, -6.0f, -25.0f));


      //  SubscribeToEvent(E_UPDATE,URHO3D_HANDLER(HelloWorld,HandleUpdate));
    int i;
    
    //SubscribeToEvent(E_UPDATE,URHO3D_HANDLER(HelloWorld,ChangeTexts));
    //for (i=0;i<5;i++){
            
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));

        SubscribeToEvents();
   // }
}

/**
 * Creates a plane underneath the entire scene
 */

Node* GameSys::CreatePlane()
{
    auto *cache = GetSubsystem<ResourceCache>();

    Node *planeNode = scene_->CreateChild("Plane");
    planeNode->SetScale(Vector3(100.0f, 100.0f, 100.0f));
    planeNode->SetRotation(Quaternion(90.0f, 0.0f, 0.0f));

    auto *planeObject = planeNode->CreateComponent<StaticModel>();
    planeObject->SetModel(cache->GetResource<Model>("Models/Plane.mdl"));
    planeObject->SetMaterial(cache->GetResource<Material>("Materials/StoneTiled.xml"));
    return planeNode;
}

/**
 * CreateShip function. Creates the enemy ship to pursue
 */

Node* GameSys::CreateShip()
{
    auto *cache = GetSubsystem<ResourceCache>();
    Node *boxNode = scene_->CreateChild("Box");
    boxNode->SetRotation(Quaternion(250.0f, -25.0f, 20.0f));
    boxNode->SetPosition(Vector3(0.0f, -1.0f, 35.0f));
    boxNode->SetScale(Vector3(0.2f, 0.2, 0.2));
    auto *boxObject = boxNode->CreateComponent<StaticModel>();
    boxObject->SetModel(cache->GetResource<Model>("Models/Ship.mdl"));
    boxObject->SetMaterial(cache->GetResource<Material>("Materials/Water.xml"));

    //boxObject->SetCastShadows(true);

    return boxNode;
    
}
/**
 * 
 * 
 */
void GameSys::MoveCamera(float timeStep)
{
    /**
     *  Do not move if the UI has a focused element (the console)
     */
    if (GetSubsystem<UI>()->GetFocusElement())
        return;

    auto* input = GetSubsystem<Input>();

    /** 
     * Movement speed as world units per second
     */
    const float MOVE_SPEED = 20.0f;
    /**
     *  Mouse sensitivity as degrees per pixel
     */
    const float MOUSE_SENSITIVITY = 0.05f;
    
    /**
     *  Use this frame's mouse motion to adjust camera node yaw and pitch.
     *  Clamp the pitch between -90 and 90 degrees
     */
    IntVector2 mouseMove = input->GetMouseMove();
    yaw_ += MOUSE_SENSITIVITY * mouseMove.x_;
    pitch_ += MOUSE_SENSITIVITY * mouseMove.y_;
    pitch_ = Clamp(pitch_, -90.0f, 90.0f);
    
    /**
     *  Construct new orientation for the camera scene node from yaw and pitch. Roll is fixed to zero
     */
    if (input->GetKeyDown(KEY_Q))
        cameraNode_->SetRotation(Quaternion(pitch_, yaw_, 0.0f));
    
    /**
     * Read WASD keys and move the camera scene node to the corresponding direction if they are pressed
     * Use the Translate() function (default local space) to move relative to the node's orientation.
     */
    if (input->GetKeyDown(KEY_W))
        cameraNode_->Translate(Vector3::FORWARD * MOVE_SPEED * timeStep);
    if (input->GetKeyDown(KEY_S))
        cameraNode_->Translate(Vector3::BACK * MOVE_SPEED * timeStep);
    if (input->GetKeyDown(KEY_A))
        cameraNode_->Translate(Vector3::LEFT * MOVE_SPEED * timeStep);
    if (input->GetKeyDown(KEY_D))
        cameraNode_->Translate(Vector3::RIGHT * MOVE_SPEED * timeStep);
}
/**
 * 
 * 
 */
void GameSys::SetupViewport()
{
    auto *renderer = GetSubsystem<Renderer>();

    /**
     * Set up a viewport to the Renderer subsystem so that the 3D scene can be seen. We need to define the scene and the camera
     * at minimum. Additionally we could configure the viewport screen size and the rendering path (eg. forward / deferred) to
     * use, but now we just use full screen and default render path configured in the engine command line options
     */
    SharedPtr<Viewport> viewport(new Viewport(context_, scene_, cameraNode_->GetComponent<Camera>()));
    renderer->SetViewport(0, viewport);
}