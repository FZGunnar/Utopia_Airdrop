
class FlareLightCar_Flare extends FlareLight
{
	void FlareLightCar_Flare()//blue
	{
		FadeIn( 1 );
		SetRadiusTo( 160 );
		SetBrightnessTo( 10 );
		SetAmbientColor( 0.2, 0.2, 0.7 );
		SetDiffuseColor( 0.2, 0.2, 0.9 );
	}
}
class FlareLightContainer_Flare extends FlareLight
{
	void FlareLightContainer_Flare()//red
	{
		FadeIn( 1 );
		SetRadiusTo( 160 );
		SetBrightnessTo( 10 );
		SetAmbientColor(1.0, 0.3, 0.3);
		SetDiffuseColor(0.8, 0.2, 0.2);
	}
}
class FlareLightCrate_Flare extends FlareLight
{
	void FlareLightCrate_Flare()//yellow
	{
		FadeIn( 1 );
		SetRadiusTo( 160 );
		SetBrightnessTo( 10 );
		SetAmbientColor( 0.6, 0.6, 0.1 );
		SetDiffuseColor( 0.7, 0.7, 0.1 );
	}
}
