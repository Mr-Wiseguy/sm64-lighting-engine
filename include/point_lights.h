#ifndef __POINT_LIGHTS_H__
#define __POINT_LIGHTS_H__

#include <PR/ultratypes.h>
#include <PR/gbi.h>
#include <macros.h>

#define LIGHT_TYPE_AMBIENT       0
#define LIGHT_TYPE_DIRECTIONAL   1
#define LIGHT_TYPE_POINT         2
#define LIGHT_TYPE_POINT_OCCLUDE 3

#define LIGHT_FLAG_OCCLUDE (1 << 0)

// The max number of point lights you can have in a scene (impacts RAM)
#define MAX_POINT_LIGHTS 32
// The max number of point lights that can be affecting a given model (impacts performance)
#define MAX_POINT_LIGHTS_ACTIVE 3


STATIC_ASSERT(MAX_POINT_LIGHTS_ACTIVE <= 6, "You cannot apply more than 6 point lights at a time!");

struct SceneLight {
    Light l;
    Vec3s worldPos;
    s16 flags;
};

extern int gPointLightCompatibilityMode;
extern Lights1 gDirectionalLight;
extern s8 gLightDir[3];
extern u8 gLightDirTransformEnabled;
extern struct SceneLight gPointLights[];
extern u8 gAreaPointLightCount;
extern u8 gPointLightCount;

void emit_light(Vec3f pos, u32 color, u32 quadraticFalloff, u32 linearFalloff);

#endif
