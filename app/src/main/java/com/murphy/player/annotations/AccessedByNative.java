package com.murphy.player.annotations;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

/**
 * Created by murphy on 2017/9/7.
 */


@Target(ElementType.FIELD)
@Retention(RetentionPolicy.CLASS)
public @interface AccessedByNative {
}
