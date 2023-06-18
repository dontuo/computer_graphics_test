#ifndef CLIPPER_H
#define CLIPPER_H

#define CLIP_MAX_NUM_VERTICES 384
#define W_CLIPPING_PLANE 0.0001f 
enum clip_axis
{
	ClipAxis_None,
	ClipAxis_Left,
	ClipAxis_Right,
	ClipAxis_Top,
	ClipAxis_Bottom,
	ClipAxis_Near,
	ClipAxis_Far,
	ClipAxis_W,
};

struct clip_vertex
{
	v4 Pos; 
	v2 Uv;
};

struct clip_result
{
	u32 NumTriangles;
	clip_vertex Vertices[CLIP_MAX_NUM_VERTICES];
};

#endif