#version 120

uniform mat4 projection_matrix;
uniform mat4 view_matrix;
uniform mat4 model_matrix;
uniform float t;
uniform float offset_from_face;

uniform vec3 u_lightPosition;
uniform float u_lightPower;
uniform vec3 u_SpotPosition;

uniform float u_PointLightParam;
uniform float u_DirLightParam;
uniform float u_SpotLightParam;

uniform float u_distanceForPoint;
uniform float u_distanceForSpot;

attribute vec4 vertex_position;
attribute vec3 vertex_normal;
attribute vec3 vertex_color;

varying vec3 frag_color;
varying vec3 resultColor;

vec3 calculateLight(vec3 lightDir, vec3 norm, vec3 viewPos, vec3 v_position, vec3 lightColor, float sizeCoeff){
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    /* Specular blick lighting */
    float specularStrength = 1.0;
    float specularFactor = 14.0;
    vec3 viewDir = normalize(viewPos - v_position);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), specularFactor);
    vec3 specular = specularStrength * spec * lightColor;
    resultColor = (diffuse + specular);

    return resultColor;
}

void main()
{
    /* Morphing and transforming operation */
    mat4 mv_matrix = view_matrix * model_matrix;

    float factor = (sin(t / 30.0) + 1.0) / 2.0;

    vec3 cube_position_3d = vertex_position.xyz + offset_from_face * vertex_normal.xyz;
    vec3 sphere_position_3d = normalize(cube_position_3d);
    vec3 morphed_position_3d = factor * cube_position_3d + (1.0 - factor) * sphere_position_3d;

    gl_Position = projection_matrix * mv_matrix * vec4(morphed_position_3d, 1.0);

    /* Model Gouraud */

    vec3 v_position = vec3(mv_matrix * vec4(morphed_position_3d, 1.0));
    vec3 v_normal = normalize(vec3(mv_matrix * vec4(vertex_normal, 0.0)));

    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    vec3 viewPos = vec3(0.0, 0.0, 0.0);
    vec3 norm = normalize(v_normal);
    vec3 lightDir = normalize(u_lightPosition - v_position);

    /* lightDir2 is lightDirection for dirLight*/

    vec3 lightDir2 = vec3(0, 0, 1);

    /* lightDir3 is lightDirection for spotLight*/
    vec3 lightDir3 = normalize(u_SpotPosition - v_position);

    //spotangle is angle of spot
    float spotAngle = 0.3f;

    float cosOfAngle = dot(u_SpotPosition, lightDir3) / (length(u_SpotPosition) * length(lightDir3));
    float newAngle = acos(cosOfAngle);

    /* Ambient lighting */
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    float d = u_distanceForPoint;
    float d_1 = u_distanceForSpot;

    float K = 0.1f;
    float sizeCoeffSpot = 1.0f;
    float sizeCoeffPoint = 1.0f;

    //spot_coeff is зависимость от расстояния d -distance. p - power k -coefficent to avoid zero division
    float distCoeffPoint = 1.0 / (d + K);
    float distCoeffSpot = 1.0 / (d_1 + K);
    float spotAngleCoeff;
    if (newAngle > spotAngle){
        spotAngleCoeff = 0;
    }
    else {
        spotAngleCoeff = (spotAngle - newAngle)/(spotAngle * spotAngle);
    }

    resultColor = (ambient + u_PointLightParam * distCoeffPoint * calculateLight(lightDir, norm, viewPos, v_position, lightColor, sizeCoeffPoint)
    + u_DirLightParam*calculateLight(lightDir2, norm, viewPos, v_position, lightColor, 1.0f)
    + u_SpotLightParam*distCoeffSpot*spotAngleCoeff*calculateLight(lightDir3, norm, viewPos, v_position, lightColor, sizeCoeffSpot)) * vertex_color;
    //change resultColor to vertexColor if you want to draw lines
    frag_color = resultColor;
}