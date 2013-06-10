/*
display.h

Display the skeleton, ground plane and other objects.			

Revision 1 - Steve Lin (CMU), Jan 14, 2002
Revision 2 - Alla Safonova and Kiran Bhat (CMU), Jan 18, 2002
Revision 3 - Jernej Barbic and Yili Zhao (USC), Feb, 2012

*/

#ifndef _DISPLAY_SKELETON_H_
#define _DISPLAY_SKELETON_H_

#include <FL/glu.h>
#include "skeleton.h"
#include "motion.h"

class DisplaySkeleton 
{

  //member functions
public: 
  enum RenderMode
  {
    BONES_ONLY, BONES_AND_LOCAL_FRAMES
  };
  enum JointColor
  {
    GREEN, RED, BLUE, NUMBER_JOINT_COLORS
  };

  DisplaySkeleton();
  ~DisplaySkeleton();

  //set skeleton for display
  void LoadSkeleton(Skeleton * pSkeleton);
  void LoadSkeleton(Skeleton * pSkeleton, float color[3]); // Set color for skeleton
  //set motion for display
  void LoadMotion(Motion * pMotion);

  //display the scene (skeleton, ground plane ....)
  void Render(RenderMode renderMode);
  //void Render1(RenderMode renderMode);
  void RenderShadow(double ground[4], double light[4]);

  void SetDisplayedSpotJoint(int jointID) {m_SpotJoint = jointID;}
  int GetDisplayedSpotJoint(void) {return m_SpotJoint;}
  int GetNumSkeletons(void) {return numSkeletons;}
  Skeleton * GetSkeleton(int skeletonIndex);
  Motion * GetSkeletonMotion(int skeletonIndex);

  void Reset(void);
  
protected:
  RenderMode renderMode;
  // Draw a particular bone
  void DrawBone(Bone *ptr, int skelNum);
  // Draw the skeleton hierarchy
  void Traverse(Bone *ptr, int skelNum);
  // Model matrix for the shadow
  void SetShadowingModelviewMatrix(double ground[4], double light[4]);
  void DrawSpotJointAxis(void);
  void SetDisplayList(int skeletonID, Bone *bone, GLuint *pBoneList);
  void SetDisplayList(int skeletonID, Bone *bone, GLuint *pBoneList, float color[3]);

  int m_SpotJoint;		//joint whose local coordinate framework is drawn
  int numSkeletons;
  Skeleton *m_pSkeleton[MAX_SKELS];		//pointer to current skeleton
  Motion *m_pMotion[MAX_SKELS];		//pointer to current motion	
  GLuint m_BoneList[MAX_SKELS];		//display list with bones

  static float jointColors[NUMBER_JOINT_COLORS][3];
};

#endif
