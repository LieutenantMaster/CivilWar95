modded class EffectSound
{
	AbstractWave CV95_GetWave()
	{
		return m_SoundWaveObject;
	}

	void CV95_SkipTo(float second)
    {
        m_SoundWaveObject.Restart();
        m_SoundWaveObject.Skip(second);
    }
};
