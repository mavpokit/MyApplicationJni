package com.mavpokit.myapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import com.example.MavpaClass;
import com.example.OmegaClass;
import com.mavpokit.KotaClass;

import java.sql.Array;
import java.util.Arrays;

public class MainActivity extends AppCompatActivity {

    public static int aaaaa = 0;
    Button button;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        KotaClass kotaClass = new KotaClass();
        aaaaa++;
        Log.d("-----", kotaClass.meow());
        aaaaa++;
        MavpaClass mavpaClass = new MavpaClass();
        aaaaa++;
        Log.d("-----", mavpaClass.sayUUA());

        OmegaClass omegaClass;



        button = (Button)findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.d("-----","clicked1");
                aaaaa++;
                String s = stringFromJNI("string from java ¼ ½ ¿ ¾ ¥",777);
                Log.d("-----",s);
                Toast.makeText(MainActivity.this,s,Toast.LENGTH_LONG).show();
                aaaaa++;
                Log.d("-----",String.valueOf( jniAverage(7,8) ));
                aaaaa++;
                Log.d("-----", Arrays.toString(jniMultiply(new int[]{1,2,3,4,5} , 10) ));
                aaaaa++;

                SyncResult syncResult;
                syncResult = (SyncResult)jniSync();
                if (syncResult!=null)
                    Log.d("--syncResult--: ", syncResult.getBook()+" "+syncResult.getColl());

            }
        });
    }

    public native String  stringFromJNI(String s, int a);
    public native double jniAverage(int a, int b);
    public native int[] jniMultiply(int[] a,int mul);
    public native SyncResult jniSync();


    static {
        System.loadLibrary("kotaNative");
    }
}
