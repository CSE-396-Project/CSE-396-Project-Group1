package com.app.ballbouncer;


import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.IOException;
import java.util.Random;
import java.util.concurrent.TimeUnit;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

public class HomeFragment extends Fragment {

    private Button button1,button2,button3;
    private ImageView ball;

    private int x,y,radius;


    @Nullable
    @Override

    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.fragment_home,container,false);

        button1 = v.findViewById(R.id.button1);
        button2 = v.findViewById(R.id.button2);
        button3 = v.findViewById(R.id.button3);

        ball = v.findViewById(R.id.ball);


        button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.d("Home","Bounce the ball");
            }
        });
        button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.d("Home","Draw square");
            }
        });
        button3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.d("Home","Draw circular");
            }
        });



        return v;
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        Thread thread = new Thread(new Runnable() {
            @Override
            public void run() {
                while (true) {
                    // delay can be reduced
                    try {
                        TimeUnit.MILLISECONDS.sleep(100);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }


                    Paint paint = new Paint();
                    paint.setColor(getResources().getColor(R.color.orange));
                    paint.setStyle(Paint.Style.FILL);

                    final Bitmap bitmap = Bitmap.createBitmap(500,500,Bitmap.Config.ARGB_8888);
                    Canvas canvas = new Canvas(bitmap);

                    //random x,y coor for now, replace it with getReq
                    //randData();
                    getReq();

                    canvas.drawCircle(x,y,radius,paint);



                    ball.post(new Runnable() {
                        @Override
                        public void run() {
                            ball.setImageBitmap(bitmap);
                        }
                    });

                }
            }
        });

        thread.start();
    }

    @Override
    public void onActivityCreated(@Nullable Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);
        //show toolbar and make drawer enable
        ((DrawerLocker) getActivity()).setDrawerEnabled(true);
    }



    private void getReq(){
        OkHttpClient client = new OkHttpClient();
        String url = "http://192.168.1.27:3000/ball";
        Request request = new Request.Builder()
                .url(url)
                .build();
        client.newCall(request).enqueue(new Callback() {
            @Override
            public void onFailure(Call call, IOException e) {
                e.printStackTrace();
            }
            @Override
            public void onResponse(Call call, Response response) throws IOException {
                if (response.isSuccessful()) {
                    final String myResponse = response.body().string();
                    String[] tokens = myResponse.split(",");
                    x = Integer.parseInt(tokens[0]);
                    y = Integer.parseInt(tokens[1]);
                    radius = Integer.parseInt(tokens[2]);
                }
            }
        });
    }

    private void randData(){
        //coordinate must between 0-500(which is bitmap weight and height) -> line 98
        //threshold 50(which is fix radius for now)
        int max_XY = 450, min_XY=50;
        Random rn = new Random();
        int range = max_XY - min_XY + 1;
        x=rn.nextInt(range) + min_XY;
        y=rn.nextInt(range) + min_XY;
    }


}
