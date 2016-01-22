using UnityEngine;
using System.Collections;
using System.IO.Ports;

public class port : MonoBehaviour {
	public SerialPort sp = new SerialPort("COM3",9600);
	void Start () {
		sp.Open();
	}
	void Update () {
		int[] indata;
		indata = new int[7];
	    if(sp.IsOpen){
			for (int i=0; i<7; i++) { indata[i] = sp.ReadByte(); }
			for(int j=0;j<7;j++){print(indata[j]);}
		}
	}
}
