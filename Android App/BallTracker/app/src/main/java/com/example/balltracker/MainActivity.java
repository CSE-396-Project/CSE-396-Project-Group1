package com.example.balltracker;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.ProgressBar;
import android.widget.TextView;

import com.example.balltracker.ui.login.LoginActivity;

import java.util.Timer;
import java.util.TimerTask;

public class MainActivity extends AppCompatActivity {

    ProgressBar pb;
    int counter = 0;
    TextView textView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView = findViewById(R.id.textView);

        prog();//loading page

//        below code has to jump to login activity but it jumps by skipping loading page !!! should be fixed to test below code first comment prog(); function.
//         Intent intentLoginPage = new Intent(MainActivity.this,LoginActivity.class);
//         startActivity(intentLoginPage);

//        to test below code comment above intent if already not commented
//        Intent intentHomePage = new Intent(MainActivity.this,HomePage.class);
//        startActivity(intentHomePage);

    }

    public boolean prog(){

        System.out.println("here here");
        pb = findViewById(R.id.progressBar);

        final Timer t = new Timer();
        TimerTask tt = new TimerTask() {
            @Override
            public void run(){
                counter++;
                textView.setText(counter + "%");
                pb.setProgress(counter);
                if(counter == 100)
                    t.cancel();

            }
        };
        t.schedule(tt,0,60);
        return true;
    }
}