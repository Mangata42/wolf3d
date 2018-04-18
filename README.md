# wolf3d
 #7th project @Ecole42

Wolf3d is a project where I discovered the RayCasting technique implemented by John Carmack in his original Wolfeinstein game.

<ul>
  <li> Compiling </li>
    <code> make </code>
   <li> Running </li>
   In order to make it work, you will have to choose one of the integrated maps in the corresponding folder. Most of the error cases are fully managed. 
   Use <code> ./wolf3d ./maps/[map] </code> to run a map. 
   You can move with the arrows, and shoot with the spacebar. 
   You can exit with the escape button. 
   <li> Map editing </li> 
   You can open a map and edit it or create one by your own. Thus, you will need to fulfill some requirements :
    <ol>
      <li> A square map is needed </li>
      <li> 0 is floor, 1 or more is wall </li>
      <li> Map boundaries must be walls </li>
      <li> A 'X' somewhere on the map is required in order to spawn </li>
      <li> No spawning point at the boundaries of the map </li>
      <li> No empty file </li>
     </ol>
    <li> Cleaning </li>
      <code> make fclean </code>
     </ul>
