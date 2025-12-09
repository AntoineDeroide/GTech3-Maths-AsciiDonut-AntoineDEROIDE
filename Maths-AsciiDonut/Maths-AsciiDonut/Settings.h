class Settings
{
public:
    Settings(int argc, char** argv);
    int GetScreenWidth() const { return m_screenWidth; }
    int GetScreenHeight() const { return m_screenHeight; }
    char GetScreenBackground() const { return m_screenBackground; }
    float GetScreenPosition() const { return m_screenPosition; }
    char GetScreenMeshProjection() const { return m_screenMeshProjection; }
    int GetMeshResolution() const { return m_meshResolution; }
    float GetMeshPosition() const { return m_meshPosition; }
    float GetMeshRotationXPerAngle() const { return m_meshRotationXAngle; }
    float GetFrameDuration() const { return m_frameDuration; }

private:
    void _ParseArguments(int argc, char** argv);

private:
    int m_screenWidth;
    int m_screenHeight;
    char m_screenBackground;
    float m_screenPosition;
    char m_screenMeshProjection;
    int m_meshResolution;
    float m_meshPosition;
    float m_meshRotationXAngle;
    float m_frameDuration; // in ms
};