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

varying vec3 frag_normal;
varying vec3 frag_position;
varying vec3 frag_color;


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
    vec3 resultColor = (diffuse + specular);

    return resultColor;
}


void main()
{
    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    vec3 viewPos = vec3(0.0, 0.0, 0.0);
    vec3 norm = normalize(frag_normal);
    vec3 lightDir = normalize(u_lightPosition - frag_position);

    /* lightDir2 is lightDirection for dirLight*/

    vec3 lightDir2 = vec3(0, 0, 1);

    /* lightDir3 is lightDirection for spotLight*/
    vec3 lightDir3 = normalize(u_SpotPosition - frag_position);

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

    vec3 resultColor = (ambient + u_PointLightParam * distCoeffPoint * calculateLight(lightDir, norm, viewPos, frag_position, lightColor, sizeCoeffPoint)
    + u_DirLightParam*calculateLight(lightDir2, norm, viewPos, frag_position, lightColor, 1.0f)
    + u_SpotLightParam*distCoeffSpot*spotAngleCoeff*calculateLight(lightDir3, norm, viewPos, frag_position, lightColor, sizeCoeffSpot)) * frag_color;
    //change resultColor to vertexColor if you want to draw lines
    gl_FragColor = vec4(resultColor, 1.0);


}
