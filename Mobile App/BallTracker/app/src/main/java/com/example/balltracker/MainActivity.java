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

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //below code has to jump to login activity but it jumps by skipping loading page !!! should be fixed to test below code first comment progressBarLoading(); function.
         Intent intentLoginPage = new Intent(MainActivity.this,LoadingActivity.class);
         startActivity(intentLoginPage);

        //to test below code comment above intent if already not commented
    }
}