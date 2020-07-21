package com.example.balltracker;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.ProgressBar;
import android.widget.TextView;

import java.util.Timer;
import java.util.TimerTask;

public class LoadingActivity extends AppCompatActivity {


    ProgressBar pb;
    int counter = 0;
    TextView textView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_loading);

        textView = findViewById(R.id.textView);
        progressBarLoading();//loading page

        Intent intentHomePage = new Intent(LoadingActivity.this,HomePage.class);
        startActivity(intentHomePage);
    }

    public void progressBarLoading(){// to display progress bar as loading bar in loading page

        pb = findViewById(R.id.progressBar);
        final Timer t = new Timer();
        TimerTask tt = new TimerTask() {
            @Override
            public void run(){
                counter++;
                textView.setText(counter + "%");//0 to 100%
                pb.setProgress(counter);
                if(counter == 100)
                    t.cancel();
            }
        };
        t.schedule(tt,0,60);
    }
}