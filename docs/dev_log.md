## 28-10
Creation of repo and simply brainstorming on the subject notes + notes from watching other repos.

## 03-11

Watching [this](https://www.youtube.com/watch?v=NbSee-XM7WA&t=1505s&pp=ygUIRERBIGluIEM%3D) video I wanted to understand raytracing a little bit better by making another small game. This will also allow me to understand the graphical library a little better and improve fundamental skills for programming (experimenting and testing without having a guide or end result). 

I hope this will not take longer than one week. For today, I merely want to install the graphical library, open a window and have a gridline drawn based on a map.

## 04-11

Worked my way through. Program now can fill in the grid with a square and remove it if clicked again.
Thinking about the cursor I learned about static and dynamic images in mlx library. At the moment I have one image that I update and push to the screen but apparently you can also sort of have layers by having different images that you can push to the window. I would like to learn a little bit more about this so I don't have to constantly draw the entire image to the screen everytime the cursor moves.

Some things I would like to implement for next session:

- Adding a little round circle that follows the mouse.
- Adding another little circle that can be moved through the wasd buttons.
- Probably for session after; drawing a line between the two points.

Most likely I will learn about layering in tomorrows session!

## 05-11

In today’s session, a function was developed to blend multiple images into a single final image for display. This allows the program to combine background, tiles, and cursor images without redrawing or recalculating them each time. The current implementation successfully displays a movable square cursor controlled with the WASD keys. The function updates the cursor’s position by erasing its previous location and redrawing it at the new coordinates. There’s no handling yet for out-of-bounds movement, which can cause crashes.

Next Steps:

- Add a second movable cursor, controlled by the arrow keys.
- Implement a line connecting the two cursors once both are functional.
- Add boundary checks to prevent crashes when moving out of bounds.
- (Optional) Explore mouse-based cursor control once hardware and hand comfort allow.

## 09-11

Still writing with left hand. So I will be brief:
Made a cursor for the mouse and print it to screen. Very slow tho

Can probs be optimized a little by having one layer for the cursors and one for the grid. Now I have two layers for the cursors and I blend them together.

Also started with a function to draw a line between the two points. Currently function is called when pressing 'l' and then only the differences between the positions get printed.

## 11-11
REduced lag significantly by haing one layer (though still laggy). Draw line between points now works.
I still need to hold the previous variables so I can remove the old line.
EDIT: Line removes now

## 16-11
Some time has passed. A lot of code has been written over the past few days. Commit messages are not too great and no logging. it was abunch of experimenting with the DDA algrotihm. My code definitely does something, but not what it needs to do.

A failed attempt but I learned a lot in the process.

Most likely I will start again tomorrow with another DDA attempt from scratch. I want to use a better approach but not too sure how. I like doing things the hard way by trial and error. But that takes time and often also a toll on my mental health... we will see

## 17-11
Short session. Tired but thought about new approach for DDA. thinking that it will help to separate the x and y component of the ray more. Hopefully that will make sense along the way

## 18-11
Getting closer to a working project. Calculating length of ray correctly now. However wall collision is still a bit wonky. From what I can see there will always be 4 scenarios to take into account. Wall collision from left to right, from right to left, from up to down and from down to up.

## 19-11
!!!!!! Wall detection has been done! We can try to shoot a bunch of rays now maybe and then technically we can go to the next stage (which is the actual game)

## 21-11
Though buggy and very much not leak proof, I think it is time to abandon our [geometry game](../geometry_game) and start with a clean slate again. For today I think I could write a small readme for the (un)finished "game". Afterwards we will have to think what the next phase is going to be. I'm thinking of having a topdown map again with a player on screen that can move around with the wasd keys. You can then shoot a beam of rays with the arrow keys. My reasons for doing this in a whole other project is cause I made too many strange choices that if I have to correct them, I end up doing more work than rewriting with the new knowledge gained.

Some pointers I'd like changed in the new version:
- Keyboard cursor is just a small image of 10x10 pixels that gets pushed to the window without having to constantly merge background and foreground.
    although, then where do I keep the rays?
- Different files for all the relevant DDA functions.
- No more mouse cursor but clicking still creates a square.
- Events are handled by a `keyboard_event` and `mouse_event` that reroute to the correct function based on the keycode.
- An event that shoots 90 rays (from -45 to 45) and beams it to the top down map.
- Another event that creates a new window showing an image of what the beams give when converted to their height on the screen. (basically a single frame of the wolfenstein game).

While writing, I think it would also be cool to have a map editor. A "simple" program that takes in the dimensions (MxN) and allows you a basic painting option much like the [square on click function](../geometry_game/square_on_click.c). When exiting it saves the map created in a .txt file or something with `1` for a wall and `0` for no-wall.

## 23-11
I realise a day later I had not written a log. Basically started the ray\_shoot program by copying a bunch of functions from the geometry\_game and altering them to fit my the new requirements (somewhat).

## 24-11
Running out of time so I have not refactored the DDA file (justcopied it). But...
- Added wall collision.
- Added player movement.
- Added creating of walls.
- Added a very simple, one directional, ray shooter that shoots 90 rays.

I'm thinking of taking the mouse cursor as the direction for the rays but that might be a tad too much effort at this stage.

LOOK!!!!

<img width="408" height="234" alt="image" src="https://github.com/user-attachments/assets/c8b6b513-3907-4d61-b914-448a276f0407" />
<img width="576" height="304" alt="image" src="https://github.com/user-attachments/assets/45014a6b-a36f-4fbb-b566-780b828c4c6e" />

## 25-11
Encountering a small bug with wall collision. There will be a small gap between the user and wall if moving DOWN or RIGHT. I think understand why (it checks the next cell even though it is on the border) but I think I will leave it.
Apart from that, I fixed a small bug in wall collision for player movement

Then there was also simple refactoring; separating functions to their own files. Looking back at my DDA algorithm, I start to wonder whether I can find the time and energy to write a tutorial/explanation for it.

Now the big next thing is converting the rays to an actual 3D like image.

I want to find a way so that *long rays appear small* and *short rays appear big*.

From the top of my head that means:

`screenlength = SOMECONSTANT * (1 / ray_length)`

The biggest raylength will quite simply result in 0 pixels. But what if we divide by 0? What is the smallest ray length we are allowed? 
And how big does that make the screenline?

Then I want to draw them to the screen. Which means I have to split the line in two and have *one half shot up* and the *other half shot down*. 
I want this so my lines all have the same middle. Otherwise it will look like a weird skyline.

Omg would you look at that...
<img width="962" height="352" alt="image" src="https://github.com/user-attachments/assets/84fde246-8538-4e52-9c74-50f57fd5d040" />

